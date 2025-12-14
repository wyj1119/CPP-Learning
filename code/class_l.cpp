#include <iostream>
#include <string>
using namespace std;

class Circle{
    
    public:
        Circle(){
            R = 0;
            print_msg = "no msg";
            cout << "初始化一个半径为" << R << "的Circle对象" << endl;
            cout << "print_msg:" << print_msg << endl;
        }
        Circle(const double &R_i){
            R = R_i;
            print_msg = "no msg";
            cout << "初始化一个半径为" << R << "的Circle对象" << endl;
            cout << "print_msg:" << print_msg << endl;
        }
        Circle(const double &R_i,const string &print_msg_i){
            R = R_i;
            print_msg = print_msg_i;
            cout << "初始化一个半径为" << R << "的Circle对象" << endl;
            cout << "print_msg:" << print_msg << endl;
        }
        Circle(const Circle &C){
            R = C.R;
            print_msg = C.print_msg;
            cout << "初始化一个半径为" << R << "的Circle对象" << endl;
            cout << "print_msg:" << print_msg << endl;
        }
        void set_R(const double &R_i){
            R = R_i;
        }

        double get_PI(){
            return PI;
        }
        double get_R(){
            return R;
        }
        double get_ZC(){
            return 2*PI*R;
        }

        ~Circle(){
            cout << "销毁一个半径为" << R << "的Circle对象" << endl;
        }
        
    private:
        double R;
        const double PI = 3.1415926;
        string print_msg;
};

int main(){
    Circle c1(0,"this is a circle ,R=0");
    Circle c2(36);
    Circle c3(c1);
    Circle c4;//使用本行代码调用无参构造函数
    //Circle c4();//这种写法不能创建对象的,编译器会将这行代码识别为函数的声明(返回值类型Circle,函数名c4的函数声明)。

    Circle c5 = Circle(2,"显示法调用构造函数");
    Circle c6 = Circle(c5);
    
    Circle c7 = 10;//隐式转换法调用构造函数 本行代码相当于 Circle c7 = Circle(10);
    double ZC = 0;

    ZC = c1.get_ZC();
    cout << ZC << endl;
    c1.set_R(15.2);
    ZC = c1.get_ZC();
    cout << ZC << endl;
    return 0;
}
