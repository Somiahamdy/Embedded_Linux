#include <iostream>
#include <math.h>
#include <string>

namespace dynamic{
    int** create2darray(int size){
        int **ptr=new int*[size];
        for(int i=0;i<size;i++){
            ptr[i]=new  int[3];
            for(int j=0;j<3;j++){
                ptr[i][j]=1;
            }
        }
        return ptr;
    }
    void deletearray(int **ptr){
         delete (ptr);
    }
}

int main(){
    int **array=dynamic::create2darray(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout << array[i][j] ;
        }
        std::cout << std::endl;
    }
    dynamic::deletearray(array);



    return 0;
}