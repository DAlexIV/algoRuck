/*
 * КДЗ-1 по дисциплине Алгоритмы и структуры данных Задача о рюкзаке
 * Alex Ivanov, BSE143(1), 14.11.15
 * Clion, Project files: main.cpp rucksack_testing.cpp rucksack.h in_params.cpp
 * in_params.h out_params.cpp out_params.h item.cpp item.h
 * base_iteration.cpp base_iteration.h
 */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>
#include "rucksack.h"
#include "base_iteration.h"

/**
     * Method that uses iterable bruteforce over with callback
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
out_params *rucksack::run_over_iter(in_params *par) {

    class iteration_implementation : public base_iteration {
    private:
        void try_to_improve() {
            int cur_w = 0;
            int cur_cost = 0;

            // Counts currunt weight and current cost
            for (int i = 0; i < par->n; ++i) {
                cur_w += cur[i] ? par->items[i].getW() : 0;
                cur_cost += cur[i] ? par->items[i].getCost() : 0;
            }

            // Checks if it better that our best
            if (cur_cost > best_cost && cur_w <= par->overall_w) {
                best_w = cur_w;
                best_cost = cur_cost;
                best = cur;
            }
        }

    public:
        iteration_implementation(in_params *par, std::string method_name)
                : base_iteration(par, method_name) {
        }

        /**
         * Runs bruteforce algo with cuts
         */
        void run() {
            for (int i = 0; i < pow(2, par->n); i++) {
                std::vector<bool>::iterator found = find(cur.begin(), cur.end(), 0);

                if (found == cur.end())
                    break;

                *found = 1;
                for (std::vector<bool>::iterator it = cur.begin(); it != found; ++it)
                    *it = 0;
                try_to_improve();
            }
        };
    };

    unsigned int start = clock();

    iteration_implementation algo = iteration_implementation(par, "Iteration algorithm");
    algo.run();

    unsigned int end = clock();

    return algo.take_solution(start, end);
}

/**
     * Method that uses recursive bruteforce  with callback
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
out_params *rucksack::run_over_rec(in_params *par) {

    /**
     * Class that implements recursive running over
     */
    class run_over_implementation : public base_iteration {
    private:
        /** Main method for recursion
         * id - id of inserted element
         * cur_w - current weight of the knapsack
         * cur_cost - current cost of the knapsack
         * state - current state of the knapstack (1 if subject is taken)
         */
        void recursion(int item_id, int cur_w, int cur_cost, std::vector<bool> state) {
            if (item_id == par->n) { // If all item are taken
                if (cur_cost > best_cost) {
                    best_w = cur_w;
                    best_cost = cur_cost;
                    best = state;
                }
            }
            else { // If there are items to put
                if (cur_w + par->items[item_id].getW() <= par->overall_w) {
                    state[item_id] = 1; // Put item
                    // Call the recursion
                    recursion(item_id + 1, cur_w + par->items[item_id].getW(),
                              cur_cost + par->items[item_id].getCost(), state);
                }
                state[item_id] = 0; // Do not put the item
                // Call the recursion
                recursion(item_id + 1, cur_w, cur_cost, state);
            }

        };
    public:
        run_over_implementation(in_params *par) : base_iteration(par, "Recursive algorithm") { }

        void start_recursion() {
            recursion(0, 0, 0, cur);
        }

    };

    unsigned int start = clock();
    run_over_implementation run = run_over_implementation(par);
    run.start_recursion();
    unsigned int end = clock();

    return run.take_solution(start, end);

}

/**
     * Method that uses dynamic programming
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
out_params *rucksack::dynamic(in_params *par) {

    /**
     * Class that represents dynamic algorithm
     */
    class dynamic_implementation {
    private:
        in_params *par; // Input params for algorithm
        // Dynamic table
        std::vector<std::vector<int>> table = std::vector<std::vector<int>>();
        // Items of the final solution
        std::vector<item> items_to_go = std::vector<item>();
        int weight = 0; // Final weight

        /**
         * Method for searching in table
         */
        void step_into(int i, int j) {
            if (table[i][j] == 0) // If there is a border
                return;
            else if (table[i][j] == table[i - 1][j]) // If we move left
                step_into(i - 1, j);
            else { // If we move left
                // Add item
                items_to_go.push_back(par->items[i - 1]);
                weight += par->items[i - 1].getW();

                // Step next
                step_into(i - 1, j - par->items[i - 1].getW());
            }
        }


    public:
        dynamic_implementation(in_params *par) {
            this->par = par;
        }

        /** Fills the table
         */
        void prepare() {
            // Fills the table with zeros
            for (int i = 0; i <= par->n; ++i) {
                table.push_back(std::vector<int>());
                for (int j = 0; j <= par->overall_w; ++j) {
                    table[i].push_back(0);
                }
            }

            // Fill with values
            for (int i = 0; i <= par->n; ++i)
                for (int j = 0; j <= par->overall_w; ++j) {
                    if (i != 0 && j != 0) {
                        int upper_value = table[i - 1][j]; // Value on the left
                        int candidate = std::max(par->items[i - 1].getCost() // Upper value
                                                 + table[i - 1][j - par->items[i - 1].getW()], table[i - 1][j]);
                        // Choosing best
                        table[i][j] = par->items[i - 1].getW() <= j ? candidate : upper_value;
                    }
                }
        }


        void fill() {
            step_into(par->n, par->overall_w);
        }


        std::vector<item> getItems_to_go() {
            return items_to_go;
        }

        int getWeight() {
            return weight;
        }

        int getCost() {
            return table[par->n][par->overall_w];
        }
    };

    unsigned int start = clock();
    dynamic_implementation dyn = dynamic_implementation(par);
    dyn.prepare();
    dyn.fill();
    unsigned int end = clock();


    return new out_params("Dynamic", double(end - start) / CLOCKS_PER_SEC,
                          dyn.getWeight(), dyn.getCost(), dyn.getItems_to_go());


}

/**
     * Method that uses recursive greedy algorithm
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
out_params *rucksack::greedy_algo(in_params *par) {
    in_params params = new in_params(par);

    // Comparator for sorting
    auto comparator = [](const item &item1, const item &item2) {
        double prod1 = (double) item1.getCost() / item1.getW();
        double prod2 = (double) item2.getCost() / item2.getW();
        return prod1 > prod2;
    };

    unsigned int start = clock();

    // Sort by item usefullness
    std::sort(params.items.begin(), params.items.end(), comparator);

    // Trying  to acquire more elements
    int added_w = 0;
    int added_c = 0;
    std::vector<item> items_to_go = std::vector<item>();
    for (int i = 0; i < params.n; ++i) {
        if (params.overall_w - added_w >= params.items[i].getW()) {
            added_w += params.items[i].getW();
            added_c += params.items[i].getCost();
            items_to_go.push_back(item(params.items[i]));
        }
    }

    unsigned int end = clock();

    return new out_params("Greedy algrithm", double(end - start) / CLOCKS_PER_SEC,
                          added_w, added_c, items_to_go);

}

int main() {
    rucksack rck = rucksack();
    rck.test();
    return 0;
}