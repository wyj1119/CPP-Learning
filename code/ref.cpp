#include <iostream>
using namespace std;

double arr[4] = {1.1,2.2,3.3,4.4};

void swap_ref(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int& set_val(int a)
{
    //int val = a; //错误写法
    static int val = a;
    return val;
}

double& change_val(int i)//返回arr数组中第i个元素的引用
{
    return arr[i];
}


int main()
{
    int a = 10;
    int &b = a;
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;//a和b的值都为100


    int x = 4;
    int y = 16;
    swap_ref(x,y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    cout << "before arr[3] = " << arr[3] << endl;
    change_val(3) = 10;//函数返回第4个元素的引用，等号为这个引用对象赋值
    cout << "after arr[3] = " << arr[3] << endl;
 
    int& val = set_val(36);//函数第一次调用初始化静态变量并返回静态变量val的引用
    cout << "0-val = " << val << endl;
    set_val(0);//函数第二次调用不会重复初始化静态变量
    cout << "1-val = " << val << endl;
    set_val(0) = 50;//利用引用实现函数作为左值，修改静态变量值
    cout << "2-val = " << val << endl;

    int t = 60;
    const int& ref_t = t * 2;
    cout << "ref_t = " << ref_t << endl;

    return 0;
}

