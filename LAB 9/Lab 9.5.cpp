#include <iostream>
#include <list>
using namespace std;

class TLB
{

    list<int> cache;
    int size;

    int hits = 0;
    int misses = 0;

public:
    TLB(int s) { size = s; }

    void access(int page)
    {

        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            if (*it == page)
            {
                hits++;
                cache.erase(it);
                cache.push_front(page);
                return;
            }
        }

        misses++;

        if (cache.size() == size)
            cache.pop_back();

        cache.push_front(page);
    }

    void stats()
    {

        cout << "Hits " << hits << endl;
        cout << "Miss " << misses << endl;

        double ratio = (double)hits / (hits + misses);

        cout << "Hit Ratio " << ratio << endl;

        double accessTime = ratio * (20 + 100) + (1 - ratio) * (20 + 100 + 100);

        cout << "Effective Access Time " << accessTime << " ns" << endl;
    }
};

int main()
{

    TLB tlb(8);

    int pages[] = {1, 2, 3, 2, 4, 1, 5, 2};

    for (int p : pages)
        tlb.access(p);

    tlb.stats();
}