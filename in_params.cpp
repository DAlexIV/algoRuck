//
// Created by dalexiv on 10.12.15.
//

#include "in_params.h"

in_params::in_params(int overall_w, int n, std::vector<int> w, std::vector<int> cost) {
    this->overall_w = overall_w;
    this->n = n;
    this->w = w;
    this->cost = cost;
}

in_params::in_params(const in_params* copy) : in_params(copy->overall_w,
    copy->n, copy->w, copy->cost){

}
std::vector<in_params> in_params::read_in_params_from_file() {

}