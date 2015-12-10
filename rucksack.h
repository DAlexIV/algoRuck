//
// Created by dalexiv on 10.12.15.
//
#include <vector>
#include <string>
#include "in_params.h"
#include "out_params.h"

#ifndef RRRRRR_HEADER_H
#define RRRRRR_HEADER_H

/**
 * Class that contains main methods for solving the problem
 * and for testing these methods
 */
class rucksack {
    std::vector<in_params> data; // All tests
public:
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
