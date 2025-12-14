#include <iostream>
#include <string>
using namespace std;

class Building;

class BadGay{
    public:
        BadGay();
        void visit_building();
        void visit_building_with_gun();
    private:
        Building *b;
};

class Building{
    friend void visit_func_global(const Building &b);
    friend void BadGay::visit_building_with_gun();
    friend class GoodGay;
    public:
        Building(){
            this->m_SittingRoom = "101";
            this->m_BedRoom = "102";
        }
        Building(string num_SittingRoom, string num_BedRoom){
            this->m_SittingRoom = num_SittingRoom;
            this->m_BedRoom = num_BedRoom;
        }

        string m_SittingRoom;
    private:
        string m_BedRoom;
};


class GoodGay{
    public:
        GoodGay();
        void visit_building();
    private:
        Building *b;
};

GoodGay::GoodGay(){
    this->b = new Building("110","111");
}

void GoodGay::visit_building(){
    cout << "GoodGay visit SittingRoom Num:" << this->b->m_SittingRoom << endl;
    cout << "GoodGay visit BedRoom Num:" << this->b->m_BedRoom << endl;
}

BadGay::BadGay(){
    this->b = new Building("220","221");
}

void BadGay::visit_building(){
    cout << "BadGay visit SittingRoom Num:" << this->b->m_SittingRoom << endl;
    cout << "BadGay can not visit BedRoom" << endl;
}
void BadGay::visit_building_with_gun(){
    cout << "BadGay visit SittingRoom Num:" << this->b->m_SittingRoom << endl;
    cout << "BadGayWithGun visit BedRoom Num:" << this->b->m_BedRoom << endl;
}

void visit_func_global(const Building &b)
{
    cout << "Golbal visit SittingRoom Num:" << b.m_SittingRoom << endl;
    cout << "Golbal visit BedRoom Num:" << b.m_BedRoom << endl;
}


int main()
{
    Building b1;
    visit_func_global(b1);

    GoodGay gg;
    gg.visit_building();
    
    BadGay bg;
    bg.visit_building();
    bg.visit_building_with_gun();
    
    return 0;
}

