#include "rucksack.h"

void rucksack::test_one(int test_n, in_params *par, out_params *(*ptr)(in_params *)) {
    out_params *result = ptr(par);
    out_params::write_number_test_to_file(test_n);
    out_params::write_test_to_file(*result);
}


rucksack::rucksack() {
    data = in_params::read_in_params_from_file();
}

void rucksack::test() {
    int n = (int) data.size();
    for (int i = 0; i < data.size(); ++i) {
        //test_one(i, &data[i], &run_over_iter);
        test_one(i, &data[i], &run_over_rec);
        //test_one(i, &data[i], &dynamic);
        test_one(i, &data[i], &greedy_algo);
    }

}

