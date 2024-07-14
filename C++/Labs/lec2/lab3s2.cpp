#include <iostream>
#include <stdlib.h>
using namespace std;

/*using struct{
    int first;
    int second;
}Pair;*/

namespace Arraypair{
    std::pair<int,int>* createarray(int size){
        std::pair<int,int>* arr=new std::pair<int,int> [size];
        return arr;
    }
    void deletearray(std::pair<int,int>* a){
        delete(a);
    }
    void setpair(std::pair<int,int>* a ,int index , int fvalue, int svalue){
        a[index].first=fvalue;
        a[index].second=svalue;
    }
    void getpair(std::pair<int,int>* a ,int index ){
        std:: cout << "first num of pair: " << a[index].first << " " ;
        std:: cout << "second num of pair: " << a[index].second;
        std:: cout << std::endl;

    }
    void printarray(std::pair<int,int>* a,int size){
        for(int i=0 ;i<size;i++){
            cout << "pair " << i << " first num: " << a[i].first << " " ;
            cout << "pair " << i << " second num: " << a[i].second ;
            std:: cout << std::endl;
        }
    }

    
}

int main(){
    int s=3;
     std::pair<int,int>* parr=Arraypair::createarray(s);
     Arraypair::setpair(parr,0,3,3);
     Arraypair::setpair(parr,1,4,4);
     Arraypair::setpair(parr,2,5,5);
     Arraypair::getpair(parr,1);
     Arraypair::printarray(parr,s);


    return 0;
}