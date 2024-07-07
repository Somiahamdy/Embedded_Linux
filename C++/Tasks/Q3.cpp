#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void BinarytoDecimal(long n){
    int reminder=0;
    int dec=0;
    int i=0;
    while(n!=0){
        reminder=n%10;
        n=n/10;
        dec+=reminder*pow(2,i);
        i++;
    }
    cout << "Decimal value: "<< dec << endl;
}
void DecimaltoBinary(int n){
    int binary[30], i=0;
    while(n>0){
        binary[i]=n%2;
        n=n/2;
        i++;
    }
    cout << "Binary value: " ;
    for(int n=i-1;n>=0;n--){
        cout << binary[n];

    }
}

int main(){
    int d=13;
    long b=1101;
    BinarytoDecimal(b);
    DecimaltoBinary(d);
    return 0;
}