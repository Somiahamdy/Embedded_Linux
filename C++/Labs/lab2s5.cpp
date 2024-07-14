#include <iostream>
using namespace std;

void ReplaceString(string& str,string n,string r){
    while(str.find(n)!=string::npos){
       str.replace(str.find(n),n.size(),r);
    }
  
    
}

int main(){
    string haystack, needle, replacement;
    cout << "enter your string " ;
    getline(cin,haystack) ;
    cout << "enter your needle " ;
    getline(cin,needle);
    cout << "enter your replacement ";
    getline(cin,replacement);
    ReplaceString(haystack,needle,replacement);
    cout << haystack;





    return 0;
}