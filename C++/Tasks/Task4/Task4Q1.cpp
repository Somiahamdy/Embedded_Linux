#include <iostream>
#include <stdlib.h> 
using namespace std;

template <typename T>
class DynamicArray{
    private:
    T* arr;
    T size;
    T capacity;
    public:
    DynamicArray(){
        arr=(T*) new int [1];
        capacity=1;
        size=0;
    }
    DynamicArray(T cap){
        arr=(T*)new int [cap]{};
        capacity=cap;
        size=0;
    }
    DynamicArray(T cap, T value){
        arr=(T*)new T [cap]{value};
        size=cap;
        capacity=cap;        
    }
    DynamicArray(iT cap, std::initializer_list<T> var){
        arr=(T*)new T [cap]{};
        size=var.size();
        capacity=cap;    
        auto* iterator=var.begin();
        for(T i=0;i<size;i++){
          arr[i]=*iterator;
          iterator++;
        }    
    }  
    DynamicArray (const DynamicArray& c){
        arr=(T*) new T [c.capacity]{};
        size=c.size;
        capacity=c.capacity;
        for(T i=0;i<size;i++){
            arr[i]=c.arr[i];
        }
    }
   void resize(){
        T* newarr=(T*) new T [capacity*2]{};
        capacity*=2;
        copy(arr, arr + capacity , newarr);
        delete[] arr;
        arr=newarr;
   }
   void pushback(int value){
    if(size==capacity){
        resize();
    }
    arr[size]=value;
    size++;
    
   }
   void popback(){
    if(size>0){
      size--;
    }
   }
   void RemoveAt(int index){
    for(int i=index;i<capacity;i++){
        arr[i]=arr[i+1];
    }
    size--;
   }
   void InsertAt(int index, int value){
    if(index>capacity){
        resize();
    }
    for(int i=index;i<size;i++){
        arr[i+1]=arr[i];
    }
    arr[index]=value;
    size++;
   }
   void deletemiddle(){
    RemoveAt(size/2);
   }
   void insertmiddle(T value){
    InsertAt(size/2,value);
   }
   void print(){
    for(int i=0;i<size;i++){
        cout << arr[i] <<" " ;
    }
    cout << endl;
   }


};

int main(){
    DynamicArray<int> d;
    d.pushback(3);
    d.pushback(5);
    d.pushback(6);
    d.print();
    d.RemoveAt(1);
    DynamicArray d2(3);
    d2.pushback(10);
    d2.pushback(20);
    d2.pushback(30);
    d2.pushback(40);
    d2.InsertAt(4,50);
    d2.print();
    DynamicArray d3(3,{30,50,60});
    d3.print();

    

    return 0;
}