#include <iostream>
#include <stdlib.h>
#include <math.h>

//#include <string.h>
using namespace std;
template <typename T>

class PAIR{
    private:
    T first;
    T second;
    public:
    PAIR(): first(" "), second(" "){}
    PAIR(T x, T y): first(x), second(y){}
    T getfirst(){
        return first;
    }
    T getsecond(){
        return second;
    }
    void setfirst(T value){
        first=value;
    }
    void setsecond(T value){
        second=value;
    }
    void setpairs(T v1,T v2){
        first=v1;
        second=v2;
    }
    void swap(){
        T temp=first;
        first=second;
        second=temp;
    }
    void print(){
        cout << "first: " << first << endl << "second: " << second << endl;
    }
   
};

int main(){
    PAIR<string> p1;
    PAIR<string> p2("hello", "world");
    p1.print();
    p2.print();
    p1.setfirst("okay");
    p1.setsecond("done");
    string fir=p1.getfirst();
    string sec=p1.getsecond();
    cout << "p2 first: " << fir << endl << "p2 second: " << sec << endl;
    p1.swap();
    p1.print();



    return 0;
}