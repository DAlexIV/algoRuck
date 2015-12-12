#include <iostream>
#include <algorithm>
#include <sstream>
#include "rucksack.h"


out_params* rucksack::run_over_iter(in_params *par) {

}

out_params* rucksack::run_over_rec(in_params *par) {

}

out_params* rucksack::dynamic(in_params *par) {

}

out_params* rucksack::greedy_algo(in_params *par) {
    in_params params = new in_params(par);
    struct my_comparator {
        inline bool operator() (const item& item1, const item& item2)
        {
            double prod1 = (double)item1.getCost() / item1.getW();
            double prod2 = (double)item2.getCost() / item2.getW();
            return prod1 < prod2;
        }
    };
    std::sort(params.items.begin(), params.items.end(), my_comparator());

    int added_w = 0;
    int added_c = 0;
    std::vector<item> items_to_go = std::vector<item>();
    for (int i = 0; i < params.n; ++i)
    {
        if (params.overall_w - added_w >= params.items[i].getW()) {
            added_w += params.items[i].getW();
            added_c += params.items[i].getCost();
            items_to_go.push_back(item(params.items[i]));
        }
    }
    out_params *outparams = new out_params("pervaya sortirovka", 0, added_w, added_c, items_to_go);
    return outparams;
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
        //test_one(n, &params, &run_over_iter);
        //test_one(n, &params, &run_over_rec);
        //test_one(n, &params, &dynamic);
        test_one(n, &params, &greedy_algo);
    }

}


using namespace std;

int main() {
    rucksack rck = rucksack();
    rck.test();
    return 0;
}