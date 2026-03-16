#include <iostream>
#include <vector>
using namespace std;

struct MemoryBlock
{
    int startAddress;
    int size;
    bool isFree;
    int processID;

    MemoryBlock(int s, int sz, bool f = true, int pid = -1)
        : startAddress(s), size(sz), isFree(f), processID(pid) {}
};

class MemoryManager
{
private:
    vector<MemoryBlock> blocks;
    const int TOTAL_MEMORY = 1048576;

public:
    MemoryManager()
    {
        blocks.push_back(MemoryBlock(0, TOTAL_MEMORY, true));
    }

    bool allocateFirstFit(int pid, int size)
    {
        for (auto &b : blocks)
        {
            if (b.isFree && b.size >= size)
            {
                b.isFree = false;
                b.processID = pid;
                return true;
            }
        }
        return false;
    }

    bool allocateBestFit(int pid, int size)
    {
        int best = -1;

        for (int i = 0; i < blocks.size(); i++)
        {
            if (blocks[i].isFree && blocks[i].size >= size)
            {
                if (best == -1 || blocks[i].size < blocks[best].size)
                    best = i;
            }
        }

        if (best != -1)
        {
            blocks[best].isFree = false;
            blocks[best].processID = pid;
            return true;
        }
        return false;
    }

    bool allocateWorstFit(int pid, int size)
    {
        int worst = -1;

        for (int i = 0; i < blocks.size(); i++)
        {
            if (blocks[i].isFree && blocks[i].size >= size)
            {
                if (worst == -1 || blocks[i].size > blocks[worst].size)
                    worst = i;
            }
        }

        if (worst != -1)
        {
            blocks[worst].isFree = false;
            blocks[worst].processID = pid;
            return true;
        }

        return false;
    }

    void displayMemory()
    {
        for (auto b : blocks)
        {
            cout << "Start:" << b.startAddress
                 << " Size:" << b.size
                 << " Free:" << b.isFree
                 << " PID:" << b.processID << endl;
        }
    }
};