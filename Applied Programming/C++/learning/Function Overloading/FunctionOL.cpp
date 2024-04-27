#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;


void printCollection(string items[], int size){

    for(int i =0; i < size; i++){
        cout << items[i] << endl;
    }

}

void printCollection(array<string, 5> items){
    printCollection(items.data(),items.size());
    

}

void printCollection(vector<string> items){
    printCollection(items.data(),items.size());
}

int main(){
    string foods1[3] ={"Apples","Grapes","Pickles"};
    array<string,5> foods2 = {"Apples","Peach","Pickles","Grapes","Burritos"};
    vector<string> foods3 = {"Mommy","Daddy"};

    foods3.push_back("Baby");

    printCollection(foods1,3);

    printCollection(foods2);

    printCollection(foods3);


}

