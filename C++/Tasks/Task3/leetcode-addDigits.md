```
class Solution {
public:
    int addDigits(int num) {
        int dig1=num%10;
        int dig2=num/10;
        int result=dig2+dig1;
        int temp=result/10;
        if(temp>0){
            return addDigits(result);
        }
        return result; 
    }
};
```
