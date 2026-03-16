#include <iostream>
#include <vector>
using namespace std;

int findOptimal(vector<int> ref, vector<int> frame, int index)
{

    int farthest = index;
    int pos = -1;

    for (int i = 0; i < frame.size(); i++)
    {

        int j;

        for (j = index; j < ref.size(); j++)
            if (frame[i] == ref[j])
                break;

        if (j == ref.size())
            return i;

        if (j > farthest)
        {
            farthest = j;
            pos = i;
        }
    }

    return pos;
}

void optimal(vector<int> ref, int frames)
{

    vector<int> frame;

    int faults = 0;

    for (int i = 0; i < ref.size(); i++)
    {

        bool found = false;

        for (int f : frame)
            if (f == ref[i])
                found = true;

        if (!found)
        {

            faults++;

            if (frame.size() < frames)
                frame.push_back(ref[i]);

            else
            {
                int pos = findOptimal(ref, frame, i + 1);
                frame[pos] = ref[i];
            }
        }
    }

    cout << "Optimal Page Faults " << faults << endl;
}

int main()
{

    vector<int> ref = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    optimal(ref, 3);
}