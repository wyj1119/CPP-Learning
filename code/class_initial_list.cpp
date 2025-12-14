#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
    	Person(int a_i, int h_i, int w_i):age(a_i), height(h_i), weight(w_i){
            person_num++;
            cout << "age:" << age << endl;
            cout << "height:" << height << endl;
            cout << "weight:" << weight << endl;
        };
    	Person(const Person &P):age(P.age), height(P.height), weight(P.weight){
            person_num++;
            cout << "age:" << age << endl;
            cout << "height:" << height << endl;
            cout << "weight:" << weight << endl;
        };
    	int age;
    	int height;
    	int weight;
        static int person_num;//类内声明

        static void print_num(){
            cout << person_num << endl;
        }
    
    private:
        static string pass_word;
};

//类外初始化
int Person::person_num = 0;
string Person::pass_word = "10086";

class Empyt_Class{
    
};
int main()
{
    Person p1(22,178,67);
    Person p2(p1);
    Person p3(p1);
    Person p4(p1);
    Person p5(p1);
    Person p6(p1);
    Person p7(p1);
    cout << "total person num:" << Person::person_num << endl;
    cout << "total person num:" << p1.person_num << endl;
    cout << "total person num:" << p7.person_num << endl;
    //Person::pass_word;//不可访问

    Person::print_num();
    p1.print_num();

    cout << "class size:" << sizeof(p1) << endl;//结果为3*4个字节 即是3个int 也就说明了成员变量和静态变量分开存储

    Empyt_Class class_test;
    cout << "empty class size:" << sizeof(class_test) << endl;//空对象的占用内存1个字节
    return 0;
}//输出的person_num都为7

