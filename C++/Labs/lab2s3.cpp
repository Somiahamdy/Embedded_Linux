#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <string.h>
using namespace std;

class PAIR{
    private:
    string first;
    string second;
    public:
    PAIR(): first(" "), second(" "){}
    PAIR(string x, string y): first(x), second(y){}
    string getfirst(){
        return first;
    }
    string getsecond(){
        return second;
    }
    void setfirst(string value){
        first=value;
    }
    void setsecond(string value){
        second=value;
    }
    void setpairs(string v1,string v2){
        first=v1;
        second=v2;
    }
    void swap(){
        string temp=first;
        first=second;
        second=temp;
    }
    void print(){
        cout << "first: " << first << endl << "second: " << second << endl;
    }
   
};

int main(){
    PAIR p1;
    PAIR p2("hello", "world");
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