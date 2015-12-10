//
// Created by dalexiv on 10.12.15.
//

#ifndef RRRRRR_IN_PARAMS_H
#define RRRRRR_IN_PARAMS_H
#include <vector>

/**
 * Represents input parameters for each test
 */
class in_params {
public:
    int overall_w; // Overall weight of rucksack
    int n; // Number of available items
    std::vector<int> w; // Weight for each item
    std::vector<int> cost; // Cost for each item
    /**
     * Default constructor
     */
    in_params(int overall_w, int n, std::vector<int> w, std::vector<int> cost);

    /**
     * Copy constructor
     */
    in_params(const in_params* copy);

    /**
     * Reads ALL params from file
     * Returns vector of params
     */
    static std::vector<in_params> read_in_params_from_file();

};



#endif //RRRRRR_IN_PARAMS_H
