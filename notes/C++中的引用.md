# C++中的引用

引用就是给变量起一个**别名**，底层通常通过指针实现，但编译器会优化为直接操作所引用的对象。

```C++
int a = 10;
int &b = a;
b = 100;
cout << "a = " << a << endl;
cout << "b = " << b << endl;//a和b的值都为100
```

### 注意事项

* 不存在空引用，引用必须连接到一块合法的内存。
* 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
* 引用必须在创建时初始化。指针可以在任何时间被初始化。
* 引用的对象必须时一个变量，而指针必须是一个地址。



## 引用作为函数参数

函数的引用参数相当于传入函数参数的别名，可以对实际参数进行修改。

```cpp
#include <iostream>
using namespace std;

void swap_ref(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
    swap_ref(x,y);//函数的引用参数a,b相当于x,y的别名
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```



## 引用作为函数返回值

将函数返回值看作一个变量，把引用作为返回值就是对给函数返回值变量起一个别名。

### 注意事项

* 注意作用域，不能返回局部变量，但是可以返回静态变量。
* 可以将函数作为左值。

```cpp
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
    return 0;
}
```

### 引用本质

在C++内部通过指针常量实现，指针常量指向不可改，所以引用也不能更改对象

```cpp
int a = 10;
int &ref = a;
int* const ref_ = a;//变量类型是int* ，指针本身是常量，指向不可变；对比const int* 指向内容是常量，内容不能改变；对比常量指针常量const int* const，指向和对应内容都不变 
```

### 常量引用

初始化常量引用时允许用任意表达式作为初始值，常量引用只能检测它引用的对象的类型，只要符合

1. 普通对象int等（等价转换为两行）
2. 字面量或表达式

```cpp
int i = 42;  
const int &r1 = i;       //正确：允许将const int & 绑定到一个普通int对象上  
const int &r2 = 42;      //正确  
const int &r3 = r1 * 2;  //正确  
int &r4 = r1 * 2;        //错误  
  
double dval = 3.14;  
const int &ri = dval;    //正确  
//等价于  
const int temp = dval;  
const int &ri = temp;  
  
int i = 42;  
int &r1 = i;  
const int &r2 = i;  
r1 = 0;                  //正确  
r2 = 0;                  //错误
```

### 关于为什么要使用常量引用传递参数

在传递大型参数（比如某个对象类）时可以避免拷贝，节省空间。

```cpp
class Employee{
    public:
    	string name;
    	string position;
};

void printEmpDetails(Employee emp)
{
    cout << emp.name << endl;
    cout << emp.position << endl;
}
```

这种直接传递形参的方式会构造一个新的emp对象，既效率低下，也浪费存储空间。

下面是常量引用版：

```cpp
void printEmpDetails(const Employee &emp)
{
    cout << emp.name << endl;
    cout << emp.position << endl;
}
```

常量引用相当于const Employee* const emp ，传递的是一个指针，效率提升
