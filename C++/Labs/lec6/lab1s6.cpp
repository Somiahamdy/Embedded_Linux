#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    int arr[10],i=0;
    int x;
    int sum=0,avg,min=arr[0],max=arr[0];
    ifstream iobj{"input.txt"};
    string str;
    if(!iobj.is_open()){
        cout << " error to open file";
    }
    while(iobj>>x){
        cout << x << " ";
        arr[i]=x;
        i++;
    }
    for(int j=0;j<10;j++){
        sum+=arr[j];
        if(min>arr[j]){
            min=arr[j];
        }
        if(max<arr[j]){
            max=arr[j];
        }
    }
    avg=sum/10;
    cout << "sum:" << sum << "avg:" << avg;
    iobj.close();
    ofstream Oobj {"output.txt"};
    if(!Oobj.is_open()){
        cout << "error to open output file";
    }
    Oobj <<"-----------------------------------------" << endl;
    Oobj << "|" << setw(5) << right << "sum" << setw(5) << right << '|' << setw(5) << right << "avg" << setw(5) << right << '|' << setw(5) << right << "min" << setw(5) << right << '|' << setw(5) << right << "max" << setw(5) << right << '|'<< endl;
    Oobj <<"-----------------------------------------" << endl;
    Oobj << "|" << setw(5) << right << sum << setw(5) << right << '|' << setw(5) << right << avg << setw(5) << right << '|' << setw(5) << right << min << setw(5) << right << '|' << setw(5) << right << max << setw(5) << right << '|'<< endl;
    Oobj <<"-----------------------------------------" << endl;


    

    return 0;
}