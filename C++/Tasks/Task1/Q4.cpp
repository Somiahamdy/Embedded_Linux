#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void printpopulation(long long pop , int per){
    int p=0;
    p=pop+pop*per;
    cout << "population: " << p << endl;
    if(pop<=1000000){
        return (printpopulation(p,per));
    }else{
        
    }
}

int main(){
    long long population=162100;
    float percentage=6.5/100;
    //using loop
    while(population<=1000000){
        population+=population*percentage;
        cout << "population: " << population << endl;
    }
    //without loop
    printpopulation(population,percentage);



    return 0;
}