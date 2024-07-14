#include <iostream>
#include <string>
using namespace std;
class Car{
    private:
    string model;
    int year;
    public:
    void set(string m,int y){
         model=m;
         year=y;
    }
    void get(){
        cout << "model:" << model << endl << "year:" << year ;
    }
};

int main(){
   Car obj;
   obj.set("BMW",2023);
   obj.get();


    return 0;
}