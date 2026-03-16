#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void FIFO(vector<int> ref, int frames)
{

    queue<int> q;
    vector<int> memory;
    int faults = 0;

    for (int page : ref)
    {

        bool found = false;

        for (int f : memory)
            if (f == page)
                found = true;

        if (!found)
        {
            faults++;

            if (memory.size() == frames)
            {
                int old = q.front();
                q.pop();

                for (int i = 0; i < memory.size(); i++)
                    if (memory[i] == old)
                        memory.erase(memory.begin() + i);
            }

            memory.push_back(page);
            q.push(page);
        }

        cout << "Frames: ";
        for (int f : memory)
            cout << f << " ";
        cout << endl;
    }

    cout << "Page Faults: " << faults << endl;
}

int main()
{

    vector<int> ref = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    FIFO(ref, 3);

    return 0;
}