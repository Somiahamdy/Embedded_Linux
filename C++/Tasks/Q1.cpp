#include <iostream>
#include <stdlib.h>
using namespace std;

int sum(int *nptr, int res){
    cout << "please enter number: ";
    cin >> *nptr;
    if(*nptr!=0){
        res+=*nptr;
        return sum(nptr,res);
    }else{
        return res;
    }
}

int main(){
    int input;
    int *ptr=&input;
    int result=0;
    int output = sum(ptr,result);
    cout << "result: " << output;

    return 0;
}
