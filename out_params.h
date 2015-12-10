//
// Created by dalexiv on 10.12.15.
//

#ifndef RRRRRR_OUT_PARAMS_H
#define RRRRRR_OUT_PARAMS_H
#include <vector>
#include <string>

/**
 * Represents output parameters for each test
 */
class out_params {
    std::string method_name; // Name of method used
    int time; // Time elapsed
    int weight; // Weight gained
    int cost; // Cost gained
    std::vector<int> nums; // Numbers of used items
    std::vector<int> w; // Weight of these items
    std::vector<int> c; // Cost of these items
public:
    /**
     * Default constructor
     */
    out_params(int time, int weight, int cost, std::vector<int> nums, std::vector<int> w, std::vector<int> c);

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
