#Rafael Maranhão Rego Praxedes

#Makefile

all:dynamic

dynamic: knapsack.o product.o main.o 
	g++ -std=c++11 knapsack.o product.o main.o -o dynamic-algorithms

knapsack.o: Algorithms/Knapsack/knapsack.cpp
	g++ -std=c++11 -c Algorithms/Knapsack/knapsack.cpp

product.o: DataStructures/Product/product.cpp
	g++ -std=c++11 -c DataStructures/Product/product.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o knapsack *~
	rm -f *.o product *~
	rm -f *.o main *~
