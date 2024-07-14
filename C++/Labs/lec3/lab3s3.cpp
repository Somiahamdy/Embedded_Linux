#include <iostream>
#include <stdlib.h> 

template <typename T1, typename T2>

class pair{
    private:
    T1 key;
    T2 value;
    public:
    void setvalues(T1 kv, T2 v){
        key=kv;
        value=v;
    }
    T1 getkeys(){
        std::cout << "key: " << key << std::endl ;

    }
    T2 getvalues(){
       std::cout << "value: " << value << std::endl;
    }
};


int main(){
  pair<int , char> p;
  p.setvalues(5,'h');
  char vret=p.getvalues();
  int kret=p.getkeys();

    return 0;
}