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

int main()
{
    deque<string> foods = {};
    ifstream file("foods.txt");
    
    string food;
    while(file >> food){
        foods.push_back(food);
    }

    print(foods);

    file.close();

}

