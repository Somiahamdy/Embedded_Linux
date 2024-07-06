#include <stdio.h>
#include "../includes/mul.h"
#include "../includes/div.h"
#include "../includes/sub.h"
#include "../includes/sum.h"

int main(){
    char choice, n1 ,n2;
    printf("enter your choice: ");
    scanf("%c",&choice);
    switch(choice){
    case '*':
       printf("%d + %d = %d",n1,n2,multiplication(n1,n2));
       break;
    case '/':
       printf("%d + %d = %d",n1,n2,division(n1,n2));
       break;
    case '-':
       printf("%d + %d = %d",n1,n2,subtraction(n1,n2));
       break;
    case '+':
       printf("%d + %d = %d",n1,n2,summation(n1,n2));
       break;       
    }
  
    return 0;
}
