#include <iostream>
#include <string>
using namespace std;


class Animal{
    public:
        Animal(){
            AnimalNum++;
            cout << "Animal constructor called\t AnimalNum:" << this->AnimalNum <<endl;
        }        
        virtual ~Animal(){
            this->AnimalNum--;
            cout << "Animal destructor callded\t AnimalNum:" << this->AnimalNum << endl;
        }

        static int AnimalNum;
};
int Animal :: AnimalNum = 0;

class Cat : public Animal{
    public:
        Cat(string Name){
            this->Name = new string(Name);
            cout << "Cat constructor called" << endl;
        }         
        ~Cat() override {
            if(this->Name != NULL){
                delete this->Name;
                this->Name = NULL;
                cout << "Cat destructor called" << endl;
            }
        }

        string *Name;
};

class Dog : public Animal{
    public:
        Dog(string Name){
            this->Name = new string(Name);
            cout << "Dog constructor called" << endl;
        }         
        ~Dog() override {
            if(this->Name != NULL){
                delete this->Name;
                this->Name = NULL;
                cout << "Dog destructor called" << endl;
            }
        }

        string *Name;
};



int main(){
    Animal *a1 = new Cat("Tom");
    Animal *a2 = new Dog("Judy");
    delete(a1);
    delete(a2);
    return 0;
}


