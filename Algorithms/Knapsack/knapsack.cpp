#include "knapsack.hpp"

int Knapsack(vector<Product> &products, vector<Product> &solution, int knapsackCapacity)
{
    vector< vector<element_t> > matrix;
    matrix.resize(products.size() + 1);

    element_t element;
    element.value = 0;
    element.is_used = false;

    int current_capacity;

    for (int i = 0; i < matrix.size(); i++){
        matrix[i].resize(knapsackCapacity + 1);
    }
    for (int j = 0; j <= knapsackCapacity; j++){
        matrix[0][j] = element;                           //init first line with 0
    }
    for (int i = 0; i <= products.size(); i++){
        matrix[i][0] = element;                           //init first column with 0
    }

    // Building the matrix
    for(int i = 1; i <= products.size(); i++){
        for(int j = 1; j <= knapsackCapacity; j++){
            if(products[i - 1].getWeigth() <= j){
                if((products[i - 1].getValue() + matrix[i - 1][j - products[i - 1].getWeigth()].value) > matrix[i - 1][j].value){
                    element.value = products[i - 1].getValue() + matrix[i - 1][j - products[i - 1].getWeigth()].value; 
                    element.is_used = true;
                }
                else{
                    element.value = matrix[i - 1][j].value;
                    element.is_used = false;
                }
            }//if
            else{
                element.value = matrix[i - 1][j].value;
                element.is_used = false;
            }
            matrix[i][j] = element;
        }//for
    }//for

    // Extracting solution from matrix
    current_capacity = knapsackCapacity;

    for(int i = products.size(); i >= 0; i--){
        if (matrix[i][current_capacity].is_used == true){
            solution.push_back(products[i - 1]);
            current_capacity -= products[i - 1].getWeigth();
        }
    }
    return matrix[products.size()][knapsackCapacity].value;
}