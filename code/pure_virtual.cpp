#include <iostream>
#include <string>
using namespace std;

class Base{
    public:
        virtual void func() = 0;
};

class SonVirtual : public Base{
    
};

class Son : public Base{
    public:
        virtual void func() override {
            cout << "I am son of Base" << endl;
        };
};

int main(){
    Base &b = *new Son;
    b.func();

    Base *bptr = new Son;
    bptr->func();

    return 0;
}
