#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

typedef struct {
    int x;
    int y;
}Vertex;

int main(){
     Vertex v[5];
     //generate rand function
     srand(static_cast<unsigned int>(std::time(nullptr)));

     for(int i=0;i<5;i++){
        v[i].x=rand() % 201 -100;
        v[i].y=rand() % 201 -100;
     }

     for(int i=0;i<5;i++){
        cout << "x" << i <<" : " <<v[i].x << " , ";
        cout << "y" << i <<" : " <<v[i].y ;
        cout << endl;
     }

    return 0;
}

