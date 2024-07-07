#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
    int secnum;
    cout << "enter your number: " ;
    cin >> secnum;
    int hours=secnum/3600;
    int minutes=(secnum-(hours*3600))/60;
    int seconds=secnum-(hours*3600)-(minutes*60);
    cout <<"H:m:s " << hours << ":" << minutes <<":" << seconds ;

    return 0;
}
