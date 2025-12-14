#include <iostream>
#include <string>
using namespace std;

class AbstractDrink{
    public:
        virtual void start() = 0;
        virtual void boil() = 0;
        virtual void brew() = 0;
        virtual void pour() = 0;
        virtual void addSomething() = 0;

        void makeDrink(){
            this->start();
            this->boil();
            this->brew();
            this->pour();
            this->addSomething();
        }
};

class Tea : public AbstractDrink{
    public:
        void start() override {
            cout << "\n煮茶开始了" << endl;
        }
        void boil() override {
            cout << "煮农夫山泉" << endl;
        }
        void brew() override {
            cout << "冲泡茶叶" << endl;
        }
        void pour() override {
            cout << "倒入茶杯中" << endl;
        } 
        void addSomething() override {
            cout << "加入枸杞" << endl;
        }
};

class Coffee : public AbstractDrink{
    public:
        void start() override {
            cout << "\n煮咖啡开始了" << endl;
        }
        void boil() override {
            cout << "煮矿泉水" << endl;
        }
        void brew() override {
            cout << "冲泡咖啡" << endl;
        }
        void pour() override {
            cout << "倒入玻璃杯中" << endl;
        } 
        void addSomething() override {
            cout << "加入牛奶" << endl;
        }
};

void makeDrink(AbstractDrink &ad){
    ad.makeDrink();
    delete &ad;
}

void makeDrink(AbstractDrink *ad){
    ad->makeDrink();
    delete ad;
}

int main(){
    makeDrink(*new Coffee);
    makeDrink(new Tea);
    return 0;
}


