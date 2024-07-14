#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std; 

typedef enum{
    Badrequest= 400,
    Notfound= 404,
    servererror=500,
    Gateway=504
}ErrorCode;

int printerror ( ErrorCode e){
    if(e==400){
        cout << "Bad Request" << endl;
    }else if(e==404){
        cout << "Not Found" << endl;
    }else if(e==500){
        cout << "Server Error" << endl;
    }else if(e==504){
        cout << "Gatewat Timeout" << endl;
    }
}

int main(){
   ErrorCode err=Badrequest;
   printerror(err);

    return 0;
}