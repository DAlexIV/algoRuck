//
// Created by dalexiv on 10.12.15.
//

#include "out_params.h"
#include <iostream>
#include <fstream>

void out_params::write_number_test_to_file(int n) {
    std::ofstream myfile;
    myfile.open("/home/dalexiv/clionProjects/rrrrrr/output_knap.txt", std::ios::app);
    myfile << "Test " << n + 1 << std::endl;
    myfile.close();
}

void out_params::write_test_to_file(out_params par) {
    std::ofstream myfile;
    myfile.open("/home/dalexiv/clionProjects/rrrrrr/output_knap.txt", std::ios::app);
    myfile << "Time elapsed "<< par.time << " seconds" << std::endl;
    myfile << "Backpack weight "<< par.weight << std::endl;
    myfile << "Backpack cost "<< par.cost << std::endl;
    for (auto &item : par.items) {
        myfile << "{id = " << item.getId() << ", w = " << item.getW()
            << ", cost = " << item.getCost() << "}" << std::endl;
    }
    myfile.close();
}

out_params::out_params(std::string name, int time, int weight, int cost, std::vector<item> items) {
    this->method_name = name;
    this->time = time;
    this->weight = weight;
    this->cost = cost;
    this->items = items;
}