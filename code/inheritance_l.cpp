#include <iostream>
#include <string>
using namespace std;

class Animal {
    public:
        void eat() {
            cout << "the animal is eating" << endl;
        }
        void sleep() {
            cout << "the animal is sleeping" << endl;
        }
};

class Dog : public Animal {
    public:
        void bark(){
            cout << "the dog is barking" << endl;
        }
};

class Cat : public Animal {
    public:
        void jump(){
            cout << "the cat is jumping" << endl;
        }
};


class Base{
    public:
        Base(){
            cout << "Base constructor called" << endl;
        }
        ~Base(){
            cout << "Base destructor called" << endl;
        }

};

class Son : public Base {
    public:
        Son(){
            cout << "Son constructor called" << endl;
        }
        ~Son(){
            cout << "Son destructor called" << endl;
        }

};

void test_base_son(){
    Son s1;
}

int main(){
    Dog d1;
    d1.eat();
    d1.sleep();
    d1.bark();

    Cat c1;
    c1.eat();
    c1.sleep();
    c1.jump();

    test_base_son();
    return 0;
}
