//
// Created by dalexiv on 10.12.15.
//

#include "out_params.h"
#include <iostream>
void out_params::write_number_test_to_file(int n) {

}

void out_params::write_test_to_file(out_params par) {
    for (int i = 0; i < par.items.size(); ++i)
        std::cout << par.items[i].getId() << " ";
}

out_params::out_params(std::string name, int time, int weight, int cost, std::vector<item> items) {
        this->method_name = name;
        this->time = time;
        this->weight = weight;
        this->cost = cost;
        this->items = items;
}