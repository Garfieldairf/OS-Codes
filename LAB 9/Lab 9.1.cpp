#include <iostream>
#include <vector>
using namespace std;

const int PAGE_SIZE = 1024;

class PageTableEntry
{
public:
    int frameNumber;
    bool valid;
    bool dirty;
    bool referenced;

    PageTableEntry()
    {
        frameNumber = -1;
        valid = false;
        dirty = false;
        referenced = false;
    }
};

class PageTable
{
private:
    vector<PageTableEntry> table;

public:
    PageTable(int pages)
    {
        table.resize(pages);
    }

    void setEntry(int page, int frame)
    {
        table[page].frameNumber = frame;
        table[page].valid = true;
    }

    int translate(int virtualAddress)
    {
        int page = virtualAddress / PAGE_SIZE;
        int offset = virtualAddress % PAGE_SIZE;

        if (!table[page].valid)
        {
            cout << "Page Fault!\n";
            return -1;
        }

        int physical = table[page].frameNumber * PAGE_SIZE + offset;

        cout << "Page Number: " << page << " Offset: " << offset << endl;
        cout << "Physical Address: " << physical << endl;

        return physical;
    }

    void display()
    {
        cout << "Page Table\n";
        for (int i = 0; i < table.size(); i++)
        {
            cout << i << " -> Frame " << table[i].frameNumber
                 << " Valid " << table[i].valid << endl;
        }
    }
};

int main()
{
    PageTable pt(8);

    pt.setEntry(0, 2);
    pt.setEntry(1, 4);
    pt.setEntry(2, 5);

    pt.display();

    pt.translate(1024);

    return 0;
}