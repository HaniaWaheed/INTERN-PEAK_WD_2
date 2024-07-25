#include <iostream>
#include <string>

using namespace std;

class Processor 
{
public:
    string processName;
    float price;

    Processor(string pName, float pPrice) : processName(pName), price(pPrice) 
    {
    
    }
};

class MainMemory 
{
public:
    int size; 
    float price;

    MainMemory(int mSize, float mPrice) : size(mSize), price(mPrice)
    {
    
    }
};

class MotherBoard
{
public:
    string compName;

    MotherBoard() : compName("intel")
    {
    
    }
};

class Computer 
{
public:
    Processor* proc;
    MainMemory* ram;
    MotherBoard* mboard;

    Computer(Processor* p, MainMemory* m) : proc(p), ram(m) 
    {
        mboard = new MotherBoard();
    }

    ~Computer() 
    {
        delete proc;   
        delete ram;   
        delete mboard; 
    }
};

int main() 
{
    string procName;
    float procPrice;
    int ramSize;
    float ramPrice;

    cout << "Enter Processor Name: ";
    cin >> procName;
    cout << "Enter Processor Price: ";
    cin >> procPrice;

    cout << "Enter Main Memory Size (GB): ";
    cin >> ramSize;
    cout << "Enter Main Memory Price: ";
    cin >> ramPrice;


    Processor* p = new Processor(procName, procPrice);
    MainMemory* m = new MainMemory(ramSize, ramPrice);

    Computer comp(p, m);

    cout << "\nComputer Attributes:" << endl;
    cout << "Processor: " << comp.proc->processName << endl;
    cout<<" Price "  << comp.proc->price << endl;
    cout <<" Main Memory: " << comp.ram->size << endl;
    cout<< " GB  " << comp.ram->price << endl;
    cout << " Motherboard: " << comp.mboard->compName << endl;

    return 0;
}
