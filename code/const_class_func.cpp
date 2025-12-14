#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        Person(int age){
            //age = age;
            this->age = age;//解决重名冲突
            this->judge = "no judgement";
        }
        
        void set_age(int age){
            this->age = age;
        }

        void showPerson() const{
            //this指针本身是一个指针常量 Person* const this
            //this->age = 100;//该函数传入的this指针是const Person* const this，即常量指针常量，不能更改指向和指向对象的值
            cout << "age:" << this->age << endl;
        }

        void showGoodJudge() const{
            this->judge = "he is a very nice people";
            cout << "Judge:" << this->judge << endl;
        }
        int age;
        mutable string judge;//加mutable的特殊变量，常函数中也能修改该值
};      

int main()
{
    Person p1(22);
    const Person p2(16);
    p1.showPerson();
    p1.showGoodJudge();

    p2.judge = "he is not so good";
    cout << "judgement of p2:" << p2.judge << endl;

    //p2.set_age(100);//常对象只能调用常函数，若调用非常函数则有可能更改属性，与常对象规则不符
    return 0;
}
