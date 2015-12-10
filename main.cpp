#include <iostream>
#include "header.h"

void out_params::write_number_test_to_file(int n) {
}

void rucksack::test_one(int test_n, in_params* par, out_params* (*ptr)(in_params*)) {
    out_params* result = ptr(par);
    out_params::write_number_test_to_file(test_n);
    out_params::write_test_to_file(*result);
}


rucksack::rucksack() {
    data = in_params::read_in_params_from_file();
}

void rucksack::test() {
    int n = (int) data.size();
    for (auto &params : data) {
        test_one(n, &params, &run_over_iter);
        test_one(n, &params, &run_over_rec);
        test_one(n, &params, &dynamic);
        test_one(n, &params, &greedy_algo);
    }

}

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}