// 
// Created by WOWUser on 10.12.2015. 
// 

#include "source.h"
#include <vector> 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <stdlib.h> 
#include <sstream> 

using namespace std;

vector<string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
in_params::in_params(int overall_w, int n, std::vector<int> w, std::vector<int> cost)
{
    this->overall_w = overall_w;
    this->n = n;
    this->w = w;
    this->cost = cost;
}

vector<in_params> Backpack::read_in_params_from_file()
{
    int NT;
    int W;
    int N;
    vector<int> w;
    vector<int> cost;
    vector<in_params> result;


    string line;
    fstream file;
    int counter = 0;
    file.open("C:/Users/WOWUser/ClionProjects/KDZ_AHUET/input_knap.txt",ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, line);
            counter++;
            if (counter == 1) {
                NT = atoi(line.c_str());
                vector<in_params> result = vector<in_params>(NT);
            }
            if (counter % 5 == 2)
                W = atoi(line.c_str());
            if (counter % 5 == 3) {
                N = atoi(line.c_str());
                vector<int> w = vector<int>(N);
                vector<int> cost = vector<int>(N);
            }
            if (counter % 5 == 4)
            {
                vector<string> vec = split(line, ' ');
                for (int i = 0; i < vec.size();i++)
                {
                    w[i] = atoi(vec[i].c_str());
                }
            }
            if (counter % 5 == 0)
            {
                vector<string> vec = split(line, ' ');
                for (int i = 0; i < vec.size();i++)
                {
                    cost[i] = atoi(vec[i].c_str());
                }

                in_params X = in_params(W,N,w,cost);
                result.push_back(X);
            }

        }
        file.close();
    }
    return result;
}
