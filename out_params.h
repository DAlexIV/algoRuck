//
// Created by dalexiv on 10.12.15.
//

#ifndef RRRRRR_OUT_PARAMS_H
#define RRRRRR_OUT_PARAMS_H
#include <vector>
#include <string>
#include "item.h"
#include "in_params.h"

/**
 * Represents output parameters for each test
 */
class out_params {
public:
    std::string method_name; // Name of method used
    double time; // Time elapsed
    int weight; // Weight gained
    int cost; // Cost gained
    std::vector<item> items; // Items

    /**
     * Default constructor
     */
    out_params(std::string name, double time, int weight, int cost, std::vector<item> items);

    /**
     * Writes one out_params instance to file
     */
    static void write_test_to_file(out_params par);

    /**
    * Writes number of done test into file
    * int n - number of tests
    */
    static void write_number_test_to_file(int n);



};

#endif //RRRRRR_OUT_PARAMS_H
