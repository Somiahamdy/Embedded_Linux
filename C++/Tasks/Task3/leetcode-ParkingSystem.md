```
class ParkingSystem {
private:
int b;
int m;
int s;
public:
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        bool output;
        switch (carType){
            case 1:
            if(b==0){
                output = false;
            }else {
                b--;
                output = true;
            }
             break;
             case 2:
             if(m==0){
                output = false;
             }else{
                m--;
                output = true;
             }
             break;
             case 3:
             if(s==0){
                output = false;
             }else{
                s--;
                output = true;
             }
             break;
        }
        return output;
    }
};
```
