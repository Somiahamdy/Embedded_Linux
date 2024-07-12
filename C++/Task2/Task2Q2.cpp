#include <iostream>
#include <math.h>

class Calculator{
    private:
    int num1;
    int num2;
    char operand;
    public:
    Calculator(int n1,int n2, char op){
        num1=n1;
        num2=n2;
        operand=op;
    }
    char getop(){
        return operand;
    }
    int sum(){
        return num1+num2;
    }
    int sub(){
        return num1-num2;
    }
    double div(){
        return num1/num2;
    }
    int mul(){
        return num1*num2;
    }
    int XOR(){
        return num1^num2;
    }
    int sq(int n){
        if(n=1){
            return sqrt(num1);
        }else {
            return sqrt(num2);
        }
        
    }

};
int main(){
    int n1,n2;
    char op;
    std::cout << "enter your numbers " << std::endl ;
    std::cin >> n1 >> n2;
    std::cout << "enter your operand " << std::endl;
    std::cin >> op;
    Calculator calc(n1,n2,op);
    int result=0;
    switch(calc.getop()){
        case '+':
        result = calc.sum();
        break;
        case '-':
        result = calc.sub();
        break;
        case '*':
        result = calc.mul();
        break;
        case '/':
        result = calc.div();
        break;
        case 's':
        result = calc.sq(1);
        break;
    }
    std::cout << "result: " << result;




    return 0;
}
