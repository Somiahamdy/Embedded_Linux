#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Vertex{
    private:
    int x;
    int y;
    public:
    void set(){
        srand(static_cast<unsigned int>(std::time(nullptr)));
        x=rand() % 201 -100;
        y=rand() % 201 -100;
    }
    int getx(){
        return x;
    }
    int gety(){
        return y;
    }
    void print(){
        string ret=" ";
        cout << "( " << x << " , " << y << " )";
    }
};

int main(){
     Vertex v;
     v.set();
     int xret=v.getx();
     int yret=v.gety();
     cout << "x:" << xret << " y:" << yret << endl;
     v.print();


    return 0;
}