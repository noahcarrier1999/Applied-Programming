#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;

template<typename T>
void print(T collection, int size)
{
    for(int i =0; i < size; i++){
        cout << collection[i] << endl;
    }
}

template<typename T>
void print(T collection)
{
    print(collection, collection.size());
}

class Food{
    public:
        string name;
        double cost;

        void print(){
            cout << name << " " << cost << endl; 
        }
};

int main()
{
   Food food;
   food.name = "Bananas";
   food.cost = 1000.99;
   food.print();

   Food food2;
   food2.name = "pickles";
   food2.cost = 500.98;
   food2.print();

   
}

