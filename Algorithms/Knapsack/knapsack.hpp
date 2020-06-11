#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

#include "../../DataStructures/Product/product.hpp"

using namespace std;

typedef struct{
    int value;
    bool is_used;
} element_t;

extern int Knapsack(vector<Product> &products, vector<Product> &solution, int knapsackCapacity);

#endif
