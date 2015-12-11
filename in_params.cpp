//
// Created by dalexiv on 10.12.15.
//

#include "in_params.h"
#include <sstream>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

in_params::in_params(int overall_w, int n, std::vector<item> items) {
    this->overall_w = overall_w;
    this->n = n;
    this->items = items;
}

in_params::in_params(const in_params *copy) : in_params(copy->overall_w,
                                                        copy->n, copy->items) {

}

std::vector<in_params> in_params::read_in_params_from_file() {
    int NT;
    int W;
    int N;
    std::vector<int> w;
    std::vector<int> cost;
    std::vector<item> items_res;
    std::vector<in_params> result;


    std::string line;
    std::fstream file;
    int counter = 0;
    file.open("/home/dalexiv/clionProjects/rrrrrr/input_knap.txt", std::ios::in);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            counter++;
            if (counter == 1) {
                NT = atoi(line.c_str());
                std::vector<in_params> result(NT);
            }
            if (counter % 5 == 2)
                W = atoi(line.c_str());
            if (counter % 5 == 3) {
                N = atoi(line.c_str());
                std::vector<int> w(N);
                std::vector<int> cost(N);
                std::vector<item> items_res(N);
            }
            if (counter % 5 == 4) {
                std::vector<std::string> vec = split(line, ' ');
                for (int i = 0; i < vec.size(); i++) {
//cout « w.size();
                    w.push_back(atoi(vec[i].c_str()));
                }
            }
            if (counter % 5 == 0) {
                std::vector<std::string> vec = split(line, ' ');
                for (int i = 0; i < vec.size(); i++) {
                    cost.push_back(atoi(vec[i].c_str()));
                    item y = item(i, w[i], cost[i]);
                    items_res.push_back(y);
                }

                in_params X = in_params(W, N, items_res);
                result.push_back(X);
            }

        }
        file.close();
    }
    return result;
}