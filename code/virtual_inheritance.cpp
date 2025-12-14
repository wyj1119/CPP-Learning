#include <iostream>
using namespace std;

class Animal{
    public:
        Animal(){
            this->m_Age = 0;
            cout << "Animal constructor called" << endl;
        }
        ~Animal(){
            cout << "Animal destructor called" << endl;
        }
        int m_Age;
};

class Sheep : virtual public Animal{
    public:
        Sheep(){
            this->m_Age = 10;
            cout << "Sheep constructor called" << endl;
        }
        ~Sheep(){           
            cout << "Sheep destructor called" << endl;
        }
};

class Camel : virtual public Animal{
    public:
        Camel(){
            this->m_Age = 20;
            cout << "Camel constructor called" << endl;
        }
        ~Camel(){
            cout << "Camel destructor called" << endl;
        }
};

class SheepCamel : public Sheep, public Camel{
    public:
        SheepCamel(){
            cout << "SheepCamel constructor called" << endl;
        }
        ~SheepCamel(){
            cout << "SheepCamel destructor called" << endl;
        }
};
class CamelSheep : public Camel, public Sheep{
    public:
        CamelSheep(){
            cout << "CamelSheep constructor called" << endl;
        }
        ~CamelSheep(){
            cout << "CamelSheep destructor called" << endl;
        }
};


int main(){
    Sheep s1;
    Camel c1;
    SheepCamel sc1;
    CamelSheep cs1;
    cout << "Animal age:" << s1.Animal::m_Age << endl;
    cout << "Animal age:" << c1.Animal::m_Age << endl;

    cout << "Animal age:" << sc1.m_Age << endl;

    cout << "Animal age:" << cs1.m_Age << endl;
    return 0;
}


