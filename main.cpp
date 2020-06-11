/*****************************************/
/* Rafael Maranhão Rego Praxedes         */
/*                                       */
/* 10/06/2020                            */
/*                                       */
/* Dynamic Algorithms - Main Function    */
/*                                       */
/*****************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DataStructures/Product/product.hpp"
#include "Algorithms/Knapsack/knapsack.hpp"

using namespace std;

bool ReadInputFile(vector<Product> &products, int &knapsackCapacity, string fileName)
{
    ifstream file;
    int n_products, id, weigth, value;
    
    Product product;

    file.open(fileName);

    if(file.is_open()){

        file >> n_products;
        file >> knapsackCapacity;
    
        for(int i = 0; i < n_products; i++){
            
            id = i;
            file >> weigth >> value;
            
            product.setId(id);
            product.setWeigth(weigth);
            product.setValue(value);

            products.push_back(product);
        }
        file.close();
    
        return true;
    }
    else{
        return false;
    }
}

void ListProducts(vector<Product> &products)
{
    for(int i = 0; i < products.size(); i++){
        cout << "Product[" << products[i].getId() + 1 << "]: " << endl;
        cout << "\t>> Weigth: " << products[i].getWeigth() << endl;
        cout << "\t>> Value: " << products[i].getValue() << endl;
    }
}

bool WriteOutputFile(vector<Product> &solution, int &solution_value, string fileName)
{
    ofstream file;
    file.open(fileName);

    if (file.is_open()){
        for(int i = solution.size() - 1; i >= 0; i--){
            file << "Product[" << solution[i].getId() + 1 << "]: " << endl;
            file << "\t>> Weigth: " << solution[i].getWeigth() << endl;
            file << "\t>> Value: " << solution[i].getValue() << endl;
        }
        file << "\nKnapsack max value (solution): " << solution_value << endl;   
        
        file.close();
        return true;
    }
    else{
        return false;
    }
}

int main(int argc, char** argv)
{
    if(string(argv[1]) == "Knapsack" || string(argv[1]) == "knapsack"){
        
        vector<Product> products, solution;
        int knapsackCapacity, maxValue;
        
        cout << ">>>>>>>>>>>>>>>>>>>> " << string(argv[2]) << " <<<<<<<<<<<<<<<<<<<<" << endl;
        
        cout << "Reading input file..." << endl;
        if(!ReadInputFile(products, knapsackCapacity, "In/" + string(argv[2]))){
            cout << "Error on read input file!" << endl;
            return -2;
        }
        //ListProducts(products);
        //cout << "\nKnapsack capacity: " << knapsackCapacity << endl;

        cout << "Running the Knapsack's algorithm..." << endl;
        maxValue = Knapsack(products, solution, knapsackCapacity);
        cout << "\t>> Knapsack max value (solution): " << maxValue << endl;

        cout << "Writing output file..." << endl;
        WriteOutputFile(solution, maxValue, "Out/" + string(argv[2]));
    }
    else{
        cout << "Error! Unspecified algorithm!" << endl;
        return -1;
    }
    cout << "Finishing the program..." << endl;

    return 0;
}