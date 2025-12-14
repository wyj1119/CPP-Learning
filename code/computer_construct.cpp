#include <iostream>
#include <string>
using namespace std;


class CPU{
    public:
        virtual void Calculate() = 0;
};

class IntelCPU : public CPU{
    public:
        void Calculate() override {
            cout << "IntelCPU is calculating" << endl;
        }
};

class AMDCPU : public CPU{
    public:
        void Calculate() override {
            cout << "AMDCPU is calculating" << endl;
        }
};

class DisplayCard{
    public:
        virtual void Display() = 0;
};

class NVDisplayCard : public DisplayCard{
    public:
        void Display() override {
            cout << "NVDisplayCard is Displaying" << endl;
        }
};

class AMDDisplayCard : public DisplayCard{
    public:
        void Display() override {
            cout << "AMDDisplayCard is Displaying" << endl;
        }
};

class Memry{
    public:
        virtual void Remember() = 0;
};

class KaiXiaMemry : public Memry{
    public:
        void Remember() override {
            cout << "KaiXiaMemry is Remembering" << endl;
        }
};

class SamsungMemry : public Memry{
    public:
        void Remember() override {
            cout << "SamsungMemry is Remembering" << endl;
        }
};


class Computer{
    public:
        Computer(CPU *CPU_i, DisplayCard *DisplayCard_i, Memry *Memry_i){
            this->m_CPU = CPU_i;
            this->m_DisplayCard = DisplayCard_i;
            this->m_Memry = Memry_i;
        }
        void Work(){
            this->m_CPU->Calculate();
            this->m_DisplayCard->Display();
            this->m_Memry->Remember();
        }
        ~Computer(){
            if(this->m_CPU){
                delete this->m_CPU;
                this->m_CPU = NULL;
            }
            if(this->m_DisplayCard){
                delete this->m_DisplayCard;
                this->m_DisplayCard = NULL;
            }
            if(this->m_Memry){
                delete this->m_Memry;
                this->m_Memry = NULL;
            }    
        }
    private:
        CPU *m_CPU;
        DisplayCard *m_DisplayCard;
        Memry *m_Memry;
};

void creatComputer(){
    Computer m_Computer1(new IntelCPU, new NVDisplayCard, new SamsungMemry);
    m_Computer1.Work();
    cout << "---------------------------------------------------------------" << endl;
    Computer *m_Computer2 = new Computer(new AMDCPU, new AMDDisplayCard, new KaiXiaMemry);
    m_Computer2->Work();
    delete m_Computer2;
}

int main(){
    creatComputer();
    return 0;
}
