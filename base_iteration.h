//
// Created by dalexiv on 13.12.15.
//

#ifndef RRRRRR_BASE_DYNAMIC_H
#define RRRRRR_BASE_DYNAMIC_H
#include "in_params.h"
#include "out_params.h"

/**
 * Represents base class for recursive and iterative algorithms
 */
class base_iteration {
protected:
    in_params *par; // Params for solving
    std::string method_name; // Name of the current method for output
    std::vector<bool> best; // Best solution
    int best_w; // Best weight
    int best_cost; // Best cost
    std::vector<bool> cur; // Current solution

public:
    /**
     * Default constructor
     */
    base_iteration() { }

    /**
     * Takes params and method name
     */
    base_iteration(in_params *par, std::string method_name);

    /**
     * Takes solution from class for solving
     * uses start and end to calculate time
     */
    out_params* take_solution(unsigned int start, unsigned int end);

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


#endif //RRRRRR_BASE_DYNAMIC_H
