#include <iostream>
using namespace std;

class Base{
    public:
    	Base(){
            this->m_Num = 10;
        }
    	Base(int num){
            this->m_Num = num;
        }
    	int m_Num;
        static int m_SNum;
};
int Base::m_SNum = 100;

class Son : public Base{
    public:
    	Son(){
            this->m_Num = 1000;
        }
    	Son(int num){
            this->m_Num = num;
        }
    	int m_Num;
        static int m_SNum;
};
int Son::m_SNum = 200;

int main(){
    Son s1;
    cout << "Son num:" << s1.m_Num << endl;
    cout << "Base num:" << s1.Base::m_Num << endl;
//通过对象访问静态成员
    cout << "Son static num:" << s1.m_SNum << endl;
    cout << "Base static num:" << s1.Base::m_SNum << endl;
//通过类名访问静态成员
    cout << "Son static num:" << Son::m_SNum << endl;
    cout << "Base static num:" << Base::m_SNum << endl;
    cout << "Base static num:" << Son::Base::m_SNum << endl;
	return 0;
}