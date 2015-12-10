//
// Created by dalexiv on 10.12.15.
//

#include "in_params.h"

in_params::in_params(int overall_w, int n, std::vector<item> items) {
    this->overall_w = overall_w;
    this->n = n;
    this->items = items;
}

in_params::in_params(const in_params* copy) : in_params(copy->overall_w,
    copy->n, copy->items){

}
std::vector<in_params> in_params::read_in_params_from_file() {

}