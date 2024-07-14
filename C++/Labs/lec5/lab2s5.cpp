#include <iostream>
#include <string_view>
using namespace std;

string ReplaceString(string_view str,string n,string r){
    string newstr{str};
    while(newstr.find(n)!=string::npos){
       newstr.replace(newstr.find(n),n.size(),r);
    }
  return newstr;
}

int main(){
    string_view haystack{"welcome to engineers world"};
    string needle, replacement;
    cout << "enter your needle " ;
    getline(cin,needle);
    cout << "enter your replacement ";
    getline(cin,replacement);
    string ret=ReplaceString(haystack,needle,replacement);
    cout << ret;

    return 0;
}