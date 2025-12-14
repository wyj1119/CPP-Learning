#include <iostream>
using namespace std;

void print(int dat)
{
    cout << "整数是" << dat << endl;
}

void print(float dat)
{
    cout << "浮点数是" << dat << endl;
}

void print(char *dat)
{
    cout << "字符串是" << dat << endl;
}


void func(int &a)
{
    cout << "func(int &a)" << endl;
}
void func(const int &a)
{
    cout << "func(const int &a)" << endl;
}

int main()
{
    char arr[11] = "1234567890";
    print(arr);

    int dat = 22;
    print(dat);

    int a = 10;
    const int b = 100;
    func(a);//调用func(int &a)
    func(10);//调用func(const int &a)
    func(b);//调用func(const int &a)
    return 0;
}

