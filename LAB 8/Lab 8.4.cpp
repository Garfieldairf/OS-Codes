#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class PageReplacementFIFO
{
private:
    int numFrames;
    queue<int> frameQueue;
    unordered_set<int> frameSet;
    int pageFaults;

public:
    PageReplacementFIFO(int f) : numFrames(f), pageFaults(0) {}

    void referencePage(int page)
    {
        if (frameSet.find(page) == frameSet.end())
        {
            pageFaults++;

            if (frameQueue.size() == numFrames)
            {
                int old = frameQueue.front();
                frameQueue.pop();
                frameSet.erase(old);
            }

            frameQueue.push(page);
            frameSet.insert(page);
        }
    }

    void simulate(vector<int> ref)
    {
        for (int p : ref)
        {
            referencePage(p);
        }
    }

    void displayResults()
    {
        cout << "Page Faults: " << pageFaults << endl;
    }
};