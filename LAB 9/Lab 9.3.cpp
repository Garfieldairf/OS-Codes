#include <iostream>
#include <vector>
#include <map>
using namespace std;

void LRU(vector<int> ref, int frames)
{

    vector<int> memory;
    map<int, int> lastUsed;

    int faults = 0;

    for (int i = 0; i < ref.size(); i++)
    {

        int page = ref[i];
        bool found = false;

        for (int f : memory)
            if (f == page)
                found = true;

        if (!found)
        {

            faults++;

            if (memory.size() == frames)
            {

                int lruPage = memory[0];
                int minTime = lastUsed[lruPage];

                for (int f : memory)
                    if (lastUsed[f] < minTime)
                    {
                        minTime = lastUsed[f];
                        lruPage = f;
                    }

                for (int j = 0; j < memory.size(); j++)
                    if (memory[j] == lruPage)
                        memory.erase(memory.begin() + j);
            }

            memory.push_back(page);
        }

        lastUsed[page] = i;
    }

    cout << "LRU Page Faults: " << faults << endl;
}

int main()
{

    vector<int> ref = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    LRU(ref, 3);

    return 0;
}