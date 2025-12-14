#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak() {
            cout << "Animal is speaking" << endl;
        }
};

class Cat : public Animal{
    public:
        virtual void speak() override{
            cout << "Cat is speaking" << endl;
        }
};

void doSpeak(Animal &a){
    a.speak();
}

int main(){
    Cat c1;
    doSpeak(c1);
    cout << sizeof(c1) << endl;
    return 0;
}

