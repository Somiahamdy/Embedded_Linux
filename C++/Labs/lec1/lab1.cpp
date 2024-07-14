#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int size;
    char carr[30];
    cout <<"enter your size " ;
    cin >> size;
    char **sarr=(char**)malloc(size*sizeof(char*));
    for(int i=0;i<size;i++){
        cout <<"enter your " << i << " string " << endl;
        cin >> carr;
        int length=sizeof(carr)/sizeof(char);
        char* cptr=(char*)malloc(length*sizeof(char));
        
        for(int j=0;j<length;j++){
            cptr[j]=carr[j];
        }
        sarr[i]=cptr;
    }
    for(int i=0;i<size;i++){
        cout << sarr[i] << endl;
    }


    return 0;
}