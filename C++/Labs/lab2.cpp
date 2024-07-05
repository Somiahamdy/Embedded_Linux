#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct {
      int *arr;
      int vsize;  //number of elements
      int capacity; //size of whole array
}vect;

void InitArr(vect *vptr,int size){
    vptr->arr=(int*)malloc(size*sizeof(int));
    vptr->vsize=size;
    vptr->capacity=size;
    cout << "enter your values" << endl;
    for(int i=0;i<size;i++){
        cin >> vptr->arr[i];
    }
}
int Insertelement(vect* vptr,int elementnum,int data){
    //check for element number limit
    if(elementnum > vptr->capacity){
        return -1;
    }
    //check for capacity 
    if(vptr->capacity==vptr->vsize){
        vptr->arr=(int*)realloc(vptr,vptr->vsize*2);
        vptr->capacity=vptr->vsize*2;
        vptr->vsize++;
    }
    for(int i=vptr->vsize;i>=elementnum;i--){
        vptr->arr[i]=vptr->arr[i-1];
        if(i==elementnum){
            vptr->arr[elementnum]=data;
        }
    }
 
    return 1;
}

int deleteelement(vect *vptr,int elementnum){
    int* parr=(int*)malloc(vptr->vsize*sizeof(int));
      //check for number limit
      if(elementnum> vptr->vsize){
        return -1;
      }
      for(int i=0;i<elementnum;i++){
        if(i<elementnum){
          parr[i]=vptr->arr[i];
        }else if(i>=elementnum){
            parr[i]=vptr->arr[i+1];
        }
      }
      vptr->arr=parr;
      vptr->vsize--;
      return 1;
}

void printarr(vect* vptr){
    for(int i=0;i<vptr->vsize;i++){
        cout << "num " << vptr->arr[i] << endl;
    }
}

int main(){
    vect v;
    InitArr(&v,5);
    printarr(&v);
    Insertelement(&v,2,10);
    printarr(&v);
    deleteelement(&v,1);
    printarr(&v);
    return 0;
}
