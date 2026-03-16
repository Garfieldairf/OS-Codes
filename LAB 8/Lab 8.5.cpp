#include <iostream>
#include <vector>
using namespace std;

struct SegmentTableEntry
{
    int base;
    int limit;
    bool valid;

    SegmentTableEntry(int b = 0, int l = 0, bool v = false)
        : base(b), limit(l), valid(v) {}
};

class SegmentationSystem
{
private:
    vector<SegmentTableEntry> table;
    const int MAX_SEGMENTS = 8;

public:
    SegmentationSystem()
    {
        table.resize(MAX_SEGMENTS);
    }

    bool addSegment(int s, int base, int limit)
    {
        if (s < 0 || s >= MAX_SEGMENTS)
            return false;

        table[s] = SegmentTableEntry(base, limit, true);
        return true;
    }

    int translateAddress(int s, int offset)
    {
        if (!table[s].valid || offset >= table[s].limit)
        {
            cout << "Segmentation Fault\n";
            return -1;
        }

        return table[s].base + offset;
    }

    void displaySegmentTable()
    {
        for (int i = 0; i < MAX_SEGMENTS; i++)
        {
            cout << "Segment " << i
                 << " Base " << table[i].base
                 << " Limit " << table[i].limit
                 << " Valid " << table[i].valid << endl;
        }
    }
};