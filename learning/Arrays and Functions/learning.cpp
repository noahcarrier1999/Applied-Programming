#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;


void printArray(string items[], int size){

    for(int i =0; i < size; i++){
        cout << items[i] << endl;
    }

}

void printSTDArray(array<string, 5> items){

    for(int i = 0; i < items.size(); i++){
        cout << items[i] << endl;
    }

}

void printVector(vector<string> items){
    for(auto item : items){
        cout << item << endl;
    }

}

int main(){
    string foods1[3] ={"Apples","Grapes","Pickles"};
    array<string,5> foods2 = {"Apples","Peach","Pickles","Grapes","Burritos"};
    vector<string> foods3 = {"Mommy","Daddy"};

    printArray(foods1,3);

    printSTDArray(foods2);

    printVector(foods3);


}

