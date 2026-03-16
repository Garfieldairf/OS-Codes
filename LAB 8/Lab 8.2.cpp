#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

const int TLB_SIZE = 8;

class TLB
{
private:
    struct TLBEntry
    {
        int pageNumber;
        int frameNumber;
    };

    list<TLBEntry> tlbCache;
    unordered_map<int, list<TLBEntry>::iterator> tlbMap;

    int hits;
    int misses;

public:
    TLB() : hits(0), misses(0) {}

    int lookup(int pageNumber)
    {
        if (tlbMap.find(pageNumber) != tlbMap.end())
        {
            hits++;
            auto it = tlbMap[pageNumber];
            tlbCache.splice(tlbCache.begin(), tlbCache, it);
            return it->frameNumber;
        }

        misses++;
        return -1;
    }

    void insert(int pageNumber, int frameNumber)
    {
        if (tlbCache.size() == TLB_SIZE)
        {
            auto last = tlbCache.back();
            tlbMap.erase(last.pageNumber);
            tlbCache.pop_back();
        }

        tlbCache.push_front({pageNumber, frameNumber});
        tlbMap[pageNumber] = tlbCache.begin();
    }

    void displayStats()
    {
        cout << "Hits: " << hits << endl;
        cout << "Misses: " << misses << endl;
        cout << "Hit Ratio: " << (double)hits / (hits + misses) << endl;
    }
};