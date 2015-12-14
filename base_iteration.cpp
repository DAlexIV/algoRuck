//
// Created by dalexiv on 13.12.15.
//

#include "base_iteration.h"

/**
 * Takes params and method name
 */
base_iteration::base_iteration(in_params *par, std::string method_name) {
    this->method_name = method_name;
    this->best = std::vector<bool>();
    this->cur = std::vector<bool>();

    this->best_w = 0;
    this->best_cost = 0;
    this->par = par;

    for (int i = 0; i < par->n; ++i)
        cur.push_back(0);
}

/**
     * Takes solution from class for solving
     * uses start and end to calculate time
     */
out_params* base_iteration::take_solution(unsigned int start, unsigned int end) {
    std::vector<item> items_to_go = std::vector<item>();
    for (int i = 0; i < par->n; ++i)
        if (this->getBestItems()[i])
            items_to_go.push_back(par->items[i]);

    return new out_params(method_name,
                          double(end - start) / CLOCKS_PER_SEC, this->getBestW(), this->getBestCost(), items_to_go);
}