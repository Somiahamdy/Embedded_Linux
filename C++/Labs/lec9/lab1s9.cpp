#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

class Spinlock{
    private:
    atomic_flag l;
    public:
    Spinlock(): l(ATOMIC_FLAG_INIT){}
    void lock(){
        while(l.test_and_set(memory_order_acquire)){ //loops until lock is acquired

        }
    }
    void unlock(){
        l.clear(memory_order_release); //releases the lock
    }

};

int main(){
    Spinlock obj1,obj2;
    thread th1([&obj1](){
        obj1.lock();
        cout << "thread one took the lock\n";
        obj1.unlock();
        cout << "thread one released the lock\n";

    });
    thread th2([&obj2](){
        obj2.lock();
        cout << "thread two took the lock\n";
        obj2.unlock();
        cout << "thread two released the lock\n";

    });
    th1.join();
    th2.join();

    return 0;
}