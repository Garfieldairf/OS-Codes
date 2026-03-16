#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_PAGES = 64;
const int NUM_FRAMES = 32;
const int PAGE_SIZE = 1024;

class PageTable
{
private:
    int pageTable[NUM_PAGES];
    bool valid[NUM_PAGES];

public:
    PageTable()
    {
        srand(time(0));
        for (int i = 0; i < NUM_PAGES; i++)
        {
            valid[i] = rand() % 2;
            if (valid[i])
                pageTable[i] = rand() % NUM_FRAMES;
            else
                pageTable[i] = -1;
        }
    }

    int translateAddress(int logicalAddress)
    {
        int page = logicalAddress / PAGE_SIZE;
        int offset = logicalAddress % PAGE_SIZE;

        if (page >= NUM_PAGES || !valid[page])
        {
            cout << "Page Fault\n";
            return -1;
        }

        int frame = pageTable[page];
        int physical = frame * PAGE_SIZE + offset;
        return physical;
    }

    void displayPageTable()
    {
        cout << "Page  Frame  Valid\n";
        for (int i = 0; i < NUM_PAGES; i++)
        {
            cout << setw(4) << i << " "
                 << setw(5) << pageTable[i] << " "
                 << valid[i] << endl;
        }
    }
};

int main()
{
    PageTable pt;
    pt.displayPageTable();

    int logical;
    cout << "Enter logical address: ";
    cin >> logical;

    int physical = pt.translateAddress(logical);

    if (physical != -1)
        cout << "Physical Address = " << physical << endl;

    return 0;
}