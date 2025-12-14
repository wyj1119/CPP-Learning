#include <iostream>
#include <string>
using namespace std;


class AbstractCal{
    public:
        virtual double getResult(){
            return 0;
        }
        double num1;
        double num2;
};

class AddCal : public AbstractCal{
    public:
        double getResult() override{
            return num1 + num2;
        }
};

class SubCal : public AbstractCal{
    public:
        double getResult() override {
            return num1 - num2;
        }
};

class Multical : public AbstractCal{
    public:
        double getResult() override {
            return num1 * num2;
        }
};


int main(){
    AbstractCal *Cal = new Multical;
    Cal->num1 = 10.0;
    Cal->num2 = 3.14;
    cout << Cal->num1 << " * " << Cal->num2 << " = " << Cal->getResult() << endl;
    delete Cal;

    Cal = new AddCal;
    Cal->num1 = 10.0;
    Cal->num2 = 3.14;
    cout << Cal->num1 << " + " << Cal->num2 << " = " << Cal->getResult() << endl;
    delete Cal;

    return 0;
}


