#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
    //普通构造函数
        Person(){
            Height = new int(160);
			age = 0;
        }
    	Person(int age_i,int H_i){
			age = age_i;
            Height = new int(160);
        }
    //拷贝构造函数
        Person(const Person &P){
			age = P.age;
            Height = new int(*P.Height);
        }
    	~Person(){
            if(Height != NULL){
                delete Height;
                Height = NULL;
            }
            cout << "destroy a Person class" << endl;
        }
        
//   private:
    	int age;
        int *Height;
};


int main(){
    Person p1(22,160);
    cout << "age:" << p1.age << "\nheight:" << *p1.Height << endl;

    Person p2(p1);
    cout << "age:" << p2.age << "\nheight:" << *p2.Height << endl;
    return 0;
}
