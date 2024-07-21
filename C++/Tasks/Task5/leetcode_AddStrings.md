```
double StringtoInteger(string str){
    double num=0;
    for(char c : str){
        if(c>='0'|| c<='9'){
            num=num*10 + (c-'0');
        }
    }
    return num;
}
class Solution {
public:
    string addStrings(string num1, string num2) {
        double n1=StringtoInteger(num1);
        double n2=StringtoInteger(num2);
        double result=n1+n2;
        return to_string((int)result);
    }
};
```
