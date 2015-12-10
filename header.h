//
// Created by dalexiv on 10.12.15.
//
#include <vector>
#include <string>

#ifndef RRRRRR_HEADER_H
#define RRRRRR_HEADER_H

/**
 * Represents input parameters for each test
 */
class in_params {
    int overall_w; // Overall weight of rucksack
    int n; // Number of available items
    std::vector<int> w; // Weight for each item
    std::vector<int> cost; // Cost for each item
public:
    /**
     * Default constructor
     */
    in_params(int overall_w, int n, std::vector<int> w, std::vector<int> cost);

    /**
     * Reads ALL params from file
     * Returns vector of params
     */
    static std::vector<in_params> read_in_params_from_file();

};

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

/**
 * Class that contains main methods for solving the problem
 * and for testing these methods
 */
class rucksack {
    std::vector<in_params> data; // All tests
private:
    /**
     * Method that uses iterable bruteforce over with callback
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
    static out_params *run_over_iter(in_params *par);

    /**
     * Method that uses recursive bruteforce  with callback
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
    static out_params *run_over_rec(in_params *par);

    /**
     * Method that uses dynamic programming
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
    static out_params *dynamic(in_params *par);

    /**
     * Method that uses recursive greedy algorithm
     * in_params *par - reference to input params for this test run
     * Returns out_params as a result of test run
     */
    static out_params *greedy_algo(in_params *par);

public:
    /**
     * Default constructor (initialize input data from file)
     */
    rucksack();


    /**
     * Tests one particular dataset of params on one particular
     * algorithm
     * int test_n - number of current tests
     * in_params *par - reference to current dataset for solving
     * out_params *(*ptr)(in_params *) - reference to current function
     *     which represents current method for
     */
    void test_one(int test_n, in_params *par, out_params *(*ptr)(in_params *));

    /**
     * Run all tests
     */
    void test();
};

#endif //RRRRRR_HEADER_H
