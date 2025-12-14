#include <iostream>
using namespace std;

class Person{
    public:

        void print_class_name(){
            cout << "Person" << endl;
        }
        void print_age(){
            if(this == NULL){
                cout << "this ptr is NULL!" << endl;
                return;
            }      
            cout << "age:" << this->m_Age << endl;
        }
        int m_Age;
};

int main(){
    Person *ptr = NULL;
    ptr->print_class_name();//空指针能够访问这个函数
    ptr->print_age();//由于this是空指针，访问this指针时会出错，可添加判断条件来规避
    return 0;
}
