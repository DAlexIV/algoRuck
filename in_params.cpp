//
// Created by dalexiv on 10.12.15.
//

#include "in_params.h"
#include "rucksack.h"
#include <iostream>
#include <sstream>

/**
 * Splits string by delimeter into elements
 */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

/**
 * Wrapper for split
 */
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

/**
     * Default constructor
     */
in_params::in_params(int overall_w, int n, std::vector<item> items) {
    this->overall_w = overall_w;
    this->n = n;
    this->items = items;
}

/**
     * Copy constructor
     */
in_params::in_params(const in_params *copy) : in_params(copy->overall_w,
                                                        copy->n, copy->items) {

}
/**
     * Reads ALL params from file
     * Returns vector of params
     */
std::vector<in_params> in_params::read_in_params_from_file() {
    int number_of_tests; // Number of tests

    // Result vector which contains in_params instances
    std::vector<in_params> result = std::vector<in_params>();

    std::string line; // Current line
    std::fstream file; // Out file
    file.open(rucksack::path + "input_knap.txt", std::ios::in);

    // If we owned it
    if (file.is_open()) {
        std::cout << "Started testing..." << std::endl;

        // Reads number of tests
        getline(file, line);
        number_of_tests = atoi(line.c_str());

        for (int k = 0; k < number_of_tests; ++k) {
            int weights; // Current weight
            int number_of_items; // Current number

            // Reads weight
            getline(file, line);
            weights = atoi(line.c_str());

            // Reads current number of items
            getline(file, line);
            number_of_items = atoi(line.c_str());

            // Creates and clears vectors
            std::vector<int> w(number_of_items);
            std::vector<int> cost(number_of_items);
            std::vector<item> items_res(number_of_items);
            w.clear();
            cost.clear();
            items_res.clear();

            // Takes and fills weight vector
            getline(file, line);
            std::vector<std::string> vec_w = split(line, ' ');
            for (int i = 0; i < vec_w.size(); i++) {
                w.push_back(atoi(vec_w[i].c_str()));
            }

            // Takes and fills costs vector
            getline(file, line);
            std::vector<std::string> vec_cost = split(line, ' ');
            for (int i = 0; i < vec_cost.size(); i++) {
                cost.push_back(atoi(vec_cost[i].c_str()));
                item y = item(i, w[i], cost[i]);
                items_res.push_back(y);
            }

            // Add it to result
            in_params current_params = in_params(weights, number_of_items, items_res);
            result.push_back(current_params);
        }

    }
    else {
        std::cout << "Sorry, your path was invalid, also you should use file name \"input_knap.txt\"" << std::endl;
    }
    file.close();

    return result;
}
