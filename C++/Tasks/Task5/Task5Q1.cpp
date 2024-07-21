#include <iostream>

using namespace std;

class Time{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
    Time(): hours(0), minutes(0), seconds(0) {
    }
    Time(int h, int m ,int s): hours(h), minutes(m), seconds(s){

    }
    void DisplayTime(void) const{
        cout <<"time:" << hours << ":" << minutes << ":" << seconds << endl;
    }
    static Time AddTime(Time t1,Time t2){
        Time t3;
        t3.hours=t1.hours + t2.hours;
        t3.minutes=t1.minutes+t2.minutes;
        t3.seconds=t1.seconds+t2.seconds;
        return t3;
    }
};

int main(){
    Time tim1(2,35,50);
    Time tim2(5,11,45);
    Time tim3;
    tim1.DisplayTime();
    tim3=Time::AddTime(tim1,tim2);
    tim3.DisplayTime();




    return 0;
}