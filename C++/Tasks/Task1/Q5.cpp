#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

typedef struct {
    char firstname[20];
    char secondname[20];
    char lastname[20];
}Name;

typedef struct {
    int day;
    int month;
    int year;
}Date;

typedef struct {
    int street;
    char city[20];
    char country[20];
}Address;

typedef struct {
    long basic;
    long additional;
    float taxes;
    float reductions;
}Salary;

typedef struct{
    Name empname;
    Date dateofbirth;
    Address empAddress;
    Salary empsalary;
    char* jop;
}Employee;

int main(){
 
    Employee newemp;
    strcpy(newemp.empname.firstname,"somia");
    strcpy(newemp.empname.secondname,"hamdy");
    strcpy(newemp.empname.lastname,"ali");
    newemp.dateofbirth.day=9;
    newemp.dateofbirth.month=2;
    newemp.dateofbirth.year=2000;
    newemp.empAddress.street=4;
    strcpy(newemp.empAddress.city,"Alexandria");
    strcpy(newemp.empAddress.country,"Egypt");
    newemp.empsalary.basic=45000;
    newemp.empsalary.additional=10000;
    newemp.empsalary.reductions=500;
    newemp.empsalary.taxes=10/100;
    strcpy(newemp.jop,"Android Engineer");
    
    cout << newemp.empname.firstname ;

    return 0;
}