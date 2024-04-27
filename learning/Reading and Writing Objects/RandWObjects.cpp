#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;



template <typename T>
void print(T collection, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << collection[i] << endl;
    }
}

template <typename T>
void print(T collection)
{
    print(collection, collection.size());
}









class Food
{
public:
    string name;
    double cost;

    void print()
    {
        cout << name << " " << cost << endl;
    }

    Food(string name, double cost)
    {
        this->name=name;
        this->cost=cost;
    }
};

void printFoods(deque<Food> foods)
{
    for(auto food : foods)
    {
        food.print();
    };
}

int main()
{
    // deque<Food> foods;

    // Food food;
    // food.name = "Bananas";
    // food.cost = 1000.99;
    // foods.push_back(food);

    // Food food2;
    // food2.name = "pickles";
    // food2.cost = 500.98;
    // foods.push_back(food2);

    // ofstream file("Foods.txt");

    // for(auto food : foods){
    //     file << food.name << " " << food.cost << endl;
    // }

    // file.close();

    deque<Food> savedFoods;
    string name;
    double cost;
    ifstream file("Foods.txt");
    while(file >> name >> cost)
    {
        savedFoods.push_back(Food(name,cost));
    }

    printFoods(savedFoods);
    

    //printFoods(foods);
}
