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

    static void printFoods(deque<Food> foods)
    {
        for(auto food : foods)
        {
            food.print();
        };
    }

    static deque<Food> readFoods(){
        deque<Food> savedFoods;
        ifstream file("Foods.txt");

        string name;
        double cost;
        while(file >> name >> cost)
        {
            savedFoods.push_back(Food(name,cost));
        }
        file.close();

        return savedFoods;
    }

    static void writeFood(deque<Food> foods)
    {
        ofstream file("Foods.txt");
        for (auto food : foods){
            file << food.name << " " << food.cost << endl;
        }
    }

    Food(string name, double cost)
    {
        this->name=name;
        this->cost=cost;
    }
};


int main()
{

    deque<Food> foods = Food::readFoods();
    Food::printFoods(foods);

    int responce = 0;
    while (responce != -1 && responce != -2){
        cout << "Choose and option:\n";
        cout << "1. Display Foods\n";
        cout << "2. Add Food to Front\n";
        cout << "3. Add Food to Back\n";
        cout << "4. Remove From the Front\n";
        cout << "5. Remove From the Back\n";
        cout << "-1. Save and Quit\n";
        cout << "-2. Quit Without Saving\n";
        cout << "Your Responce: ";

        cin >> responce;
        cout << '\n';
        string name;
        double cost;
        switch(responce)
        {
            case 1:
               Food::printFoods(foods);
               break;
            case 2: 
                cout << "Food and cost? Example: Pizza 42.32";
                cin >> name >> cost;
                foods.push_front(Food(name,cost));
                break;
            case 3:
                cout << "Food and cost? Example: Pizza 42.32";
                cin >> name >> cost;
                foods.push_back(Food(name,cost));
                break;
            case 4:
                cout << "Removing " << foods.front().name << "...\n";
                foods.pop_front();
                break;
            case 5:
                cout << "Removing " << foods.back().name << "...\n";
                foods.pop_back();
                break;
            case -1:
                Food::writeFood(foods);
                break;
            case -2:
                break;



        }
    }
    

    //printFoods(foods);
}
