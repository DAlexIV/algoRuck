#include <iostream>
#include <algorithm>
#include <sstream>
#include <ctime>
#include "rucksack.h"


out_params *rucksack::run_over_iter(in_params *par) {

}


out_params *rucksack::run_over_rec(in_params *par) {
    class run_over_implementation {
    private:
        in_params *par;
        std::vector<bool> best = std::vector<bool>();
        std::vector<bool> state = std::vector<bool>();
        int best_w = 0;
        int best_cost = 0;

        void recursion(int item_id, int cur_w, int cur_cost, std::vector<bool> state) {
            if (item_id == par->n) {
                if (cur_cost > best_cost) {
                    best_w = cur_w;
                    best_cost = cur_cost;
                    best = state;
                }
            }
            else {
                if (cur_w + par->items[item_id].getW() <= par->overall_w) {
                    state[item_id] = 1;
                    recursion(item_id + 1, cur_w + par->items[item_id].getW(),
                              cur_cost + par->items[item_id].getCost(), state);
                }
                state[item_id] = 0;
                recursion(item_id + 1, cur_w, cur_cost, state);
            }

        };
    public:
        void start_recursion() {
            recursion(0, 0, 0, state);
        }

        run_over_implementation(in_params *par) {
            this->par = par;
            for (int i = 0; i < par->n; ++i)
                state.push_back(0);
        }

        std::vector<bool> getBestItems() {
            return best;
        }

        int getBestW() {
            return best_w;
        }

        int getBestCost() {
            return best_cost;
        }
    };

    unsigned int start = clock();
    run_over_implementation run = run_over_implementation(par);
    run.start_recursion();
    std::vector<item> items_to_go = std::vector<item>();
    for (int i = 0; i < par->n; ++i)
        if (run.getBestItems()[i])
            items_to_go.push_back(par->items[i]);
    unsigned int end = clock();
    return new out_params("Running over with recursion",
                          double(end - start) / CLOCKS_PER_SEC, run.getBestW(), run.getBestCost(), items_to_go);
}

out_params *rucksack::dynamic(in_params *par) {
    class dynamic_implementation {
    private:
        in_params *par;
        std::vector<std::vector<int>> table = std::vector<std::vector<int>>();
        std::vector<item> items_to_go = std::vector<item>();
        int weight = 0;

        void step_into(int i, int j) {
            if (table[i][j] == 0)
                return;
            else if (table[i][j] == table[i - 1][j])
                step_into(i - 1, j);
            else {
                items_to_go.push_back(par->items[i - 1]);
                weight += par->items[i - 1].getW();
                step_into(i - 1, j - par->items[i - 1].getW());
            }
        }


    public:
        dynamic_implementation(in_params *par) {
            this->par = par;
        }

        void prepare() {
            for (int i = 0; i <= par->n; ++i) {
                table.push_back(std::vector<int>());
                for (int j = 0; j <= par->overall_w; ++j) {
                    table[i].push_back(0);
                }
            }

            for (int i = 0; i <= par->n; ++i)
                for (int j = 0; j <= par->overall_w; ++j) {
                    if (i != 0 && j != 0) {
                        int upper_value = table[i - 1][j];
                        int candidate = std::max(par->items[i - 1].getCost()
                                                 + table[i - 1][j - par->items[i - 1].getW()], table[i - 1][j]);
                        table[i][j] = par->items[i - 1].getW() <= j ? candidate : upper_value;
                    }
                }
        }


        void fill() {
            step_into(par->n, par->overall_w);
        }


        std::vector<item> getItems_to_go()  {
            return items_to_go;
        }

        int getWeight()  {
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

out_params *rucksack::greedy_algo(in_params *par) {
    in_params params = new in_params(par);
    struct my_comparator {
        inline bool operator()(const item &item1, const item &item2) {
            double prod1 = (double) item1.getCost() / item1.getW();
            double prod2 = (double) item2.getCost() / item2.getW();
            return prod1 > prod2;
        }
    };
    unsigned int start = clock();
    std::sort(params.items.begin(), params.items.end(), my_comparator());

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