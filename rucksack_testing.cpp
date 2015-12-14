#include "rucksack.h"
#include <iostream>

std::string rucksack::path = "";

/**
     * Tests one particular dataset of params on one particular
     * algorithm
     * int test_n - number of current tests
     * in_params *par - reference to current dataset for solving
     * out_params *(*ptr)(in_params *) - reference to current function
     *     which represents current method for
     */
void rucksack::test_one(int test_n, in_params *par, out_params *(*ptr)(in_params *)) {
    out_params *result = ptr(par);
    out_params::write_number_test_to_file(test_n);
    out_params::write_test_to_file(*result);
}

/**
     * Default constructor (initialize input data from file)
     */
rucksack::rucksack() {
    std::string dir;
    std::cout << "Please specify input and output files directory, like it done below:" << std::endl;
    std::cout << "/home/dalexiv/clionProjects/rrrrrr/" << std::endl;
    std::cin >> dir;
    path = dir;
    data = in_params::read_in_params_from_file();
}

/**
     * Run all tests
     */
void rucksack::test() {
    int n = (int) data.size();
    for (int i = 0; i < data.size(); ++i) {
        test_one(i, &data[i], &run_over_iter);
        test_one(i, &data[i], &run_over_rec);
        test_one(i, &data[i], &dynamic);
        test_one(i, &data[i], &greedy_algo);
    }
    std::cout << "We have finished, congrats!" << std::endl;

}

