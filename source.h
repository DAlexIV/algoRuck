//
// Created by WOWUser on 10.12.2015. 
// 

#include <vector> 
using namespace std;
class in_params {
    int overall_w;
    int n;
    std::vector<int> w;
    std::vector<int> cost;
public:
    in_params();
    in_params(int overall_w, int n, std::vector<int> w, std::vector<int> cost);
};

class Backpack
{
public:
    vector<in_params> read_in_params_from_file();
};