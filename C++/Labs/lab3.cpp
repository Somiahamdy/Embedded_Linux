#include <iostream>
#include <stdlib.h>
using namespace std;

int sum(int *subarr,int size){
    int result=0;
    for(int i=0;i<size;i++){
        result+=subarr[i];
    }
   return result;
}
typedef int* (*callfunc)(int **arr,int size,int* rowsize,int (*sumfunc)(int*,int));
int* sumcall(int **parr,int si,int* r, int (*sf)(int* a,int siz)){
    int *retarr;
    for(int i=0;i<si;i++){
        int result=sf(parr[i],r[i]);
        retarr[i]=result;
    }
    return retarr;
           
}

void arrprint(int *arr,int size){
    for(int i=0;i<size;i++){
        cout << "sum "<< i << " is: " << arr[i] << endl;
    }
}

int main(){
    int asize=3;
    int a1[]={2,6,8,5};
    int a2[]={10,5,9};
    int a3[]={2,3,4,5,6,7};

    int s1=sizeof(a1)/sizeof(int);
    int s2=sizeof(a2)/sizeof(int);
    int s3=sizeof(a3)/sizeof(int);

    int rowsize[]={s1,s2,s3};
    int *fullarr[]={a1,a2,a3};
    
    int *retarr=sumcall(fullarr,asize,rowsize,sum);

    arrprint(retarr,asize);


    return 0;
}
