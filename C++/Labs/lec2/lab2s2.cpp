#include <iostream>
#include <math.h>
#include <string>


namespace math{
    void print(double n){
        std::cout << "result:" << sqrt(n) << std::endl;
    }
}
namespace Stringfun{
    void print(std::string s){
        int size =sizeof(s);
        std::cout << size;
        for(int i=0;i<5;i++){
         if(isupper(s[i])){
            std::cout  << (char)tolower(s[i]);
        }else if (std::islower(s[i])){
            std::cout << (char)toupper(s[i]);
        }

        }
 
    }
    
}
namespace Array{
    void print(int *ptr,int size){
        for(int i=size-1;i>=0;i--){
            std::cout << ptr[i] ;
        }
    }
}

int main(){
    
    int num=9;
    math::print(num);
    std::string c="hello";
    Stringfun ::print(c);
    std:: cout << std::endl;
    int arr[]={1,2,3,4,5};
    Array::print(arr,5);
    
    return 0;
}