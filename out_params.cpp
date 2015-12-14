//
// Created by dalexiv on 10.12.15.
//

#include "out_params.h"
#include "rucksack.h"
#include <iostream>
#include <fstream>

/**
    * Writes number of done test into file
    * int n - number of tests
    */
void out_params::write_number_test_to_file(int n) {
    std::ofstream myfile;
    myfile.open(rucksack::path + "output_knap.txt", std::ios::app);
    myfile << "Test " << n + 1 << std::endl;
    myfile.close();
}

/**
     * Writes one out_params instance to file
     */
void out_params::write_test_to_file(out_params par) {
    std::ofstream myfile;
    myfile.open(rucksack::path + "output_knap.txt", std::ios::app);
    myfile << par.method_name << std::endl;
    myfile << "Time elapsed " << par.time << " seconds" << std::endl;
    myfile << "Rucksack weight " << par.weight << std::endl;
    myfile << "Rucksack cost " << par.cost << std::endl;
    for (auto &item : par.items) {
        myfile << "{id = " << item.getId() << ", w = " << item.getW()
        << ", cost = " << item.getCost() << "}" << std::endl;
    }
    myfile.close();

    // Console output
    std::cout << par.method_name << std::endl;
    std::cout << "Time elapsed " << par.time << " seconds" << std::endl;
    std::cout<< "Rucksack weight " << par.weight << std::endl;
    std::cout<< "Rucksack cost " << par.cost << std::endl;
    for (auto &item : par.items) {
        std::cout << "{id = " << item.getId() << ", w = " << item.getW()
        << ", cost = " << item.getCost() << "}" << std::endl;
    }
}

/**
     * Default constructor
     */
out_params::out_params(std::string name, double time, int weight, int cost, std::vector<item> items) {
    this->method_name = name;
    this->time = time;
    this->weight = weight;
    this->cost = cost;
    this->items = items;
}