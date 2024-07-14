#include <iostream>
#include <stdlib.h> 
using namespace std;

enum {
     typeint,
     typechar,
     typedouble
}arrtype;

class Array{
    private:
    void** arr;
    public:
    Array(int size){
        void** arr=new void* [size]{};
    }
    ~Array(){
        delete arr;
    }
    void setvalue(void* data,int index, int type){       
            arr[index]=data;
    }
    void getvalue(int index){
        cout << arr[index];
    }

};


int main(){
 Array a(3);
 int value=5;
 a.setvalue(&value,0,0);
 a.getvalue(0);


    return 0;
}