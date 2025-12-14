#include <iostream>
using namespace std;

template<typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 0;
    int b = 100;
    mySwap<int>(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    char x = 'x';
    char y = 'y';
    mySwap<char>(x,y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}
