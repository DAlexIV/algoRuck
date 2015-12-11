//
// Created by dalexiv on 10.12.15.
//

#ifndef RRRRRR_IN_PARAMS_H
#define RRRRRR_IN_PARAMS_H
#include <vector>
#include <string>
#include <fstream>
#include "item.h"

/**
 * Represents input parameters for each test
 */
class in_params {
public:
    int overall_w; // Overall weight of rucksack
    int n; // Number of available items
    std::vector<item> items; // Items

    in_params() { }

    /**
     * Default constructor
     */
    in_params(int overall_w, int n, std::vector<item> items);

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
