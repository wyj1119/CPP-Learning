#include <iostream>
using namespace std;

class Person{
    public:
        Person(int age){
            //age = age;
            this->age = age;//解决重名冲突
        }
        Person& PersonAddAge(const Person &p){
            this->age += p.age;
            return *this;//返回这个对象
        }
        Person* PersonAddAge_return_ptr(const Person &p){
            this->age += p.age;
            return this;//返回指向这个对象的指针
        }
        int age;
};

int main()
{
    Person p1(22);
    Person p2(16);
    cout << "age of p1:" << p1.age << endl;

    p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);//链式编程 22+16+16+16
    cout << "after age of p1:" << p1.age << endl;

    p2.PersonAddAge_return_ptr(p1)->PersonAddAge_return_ptr(p1)->PersonAddAge_return_ptr(p1);
    cout << "after age of p2:" << p2.age << endl;
    return 0;
}
