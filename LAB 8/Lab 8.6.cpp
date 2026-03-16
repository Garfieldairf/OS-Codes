#include <iostream>
#include <map>
#include <list>
#include <cmath>
using namespace std;

struct Block
{
    int address;
    int size;
    bool isFree;

    Block(int a, int s) : address(a), size(s), isFree(true) {}
};

class BuddySystem
{
private:
    map<int, list<Block>> freeLists;

    int nextPowerOf2(int size)
    {
        int p = 1;
        while (p < size)
            p *= 2;
        return p;
    }

    int findBuddy(int addr, int size)
    {
        return addr ^ size;
    }

public:
    BuddySystem()
    {
        freeLists[1024].push_back(Block(0, 1024));
    }

    void displayFreeLists()
    {
        for (auto &p : freeLists)
        {
            cout << "Size " << p.first << " : ";
            for (auto b : p.second)
                cout << b.address << " ";
            cout << endl;
        }
    }
};