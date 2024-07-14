#include <iostream>

int main(){
    std::string text="the cycle of life is a cycle of cycles";
    std::cout << text << std::endl;
    while(text.find("cycle")!=-1){
        text.replace(text.find("cycle"),5,"circle");
    }
    std::cout << text << std::endl;
    text.insert(4,"great ");
    std::cout << text << std::endl;
    text.insert(30,"never-ending ");
    std::cout << text << std::endl;

    
    return 0;
}