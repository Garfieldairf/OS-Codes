#include <iostream>
#include <vector>
#include <set>
using namespace std;

void workingSet(vector<int> ref, int window)
{

    for (int i = 0; i < ref.size(); i++)
    {

        set<int> ws;

        for (int j = max(0, i - window + 1); j <= i; j++)
            ws.insert(ref[j]);

        cout << "Time " << i + 1 << " Page " << ref[i] << " WS { ";

        for (int p : ws)
            cout << p << " ";

        cout << "} Size " << ws.size() << endl;
    }
}

int main()
{

    vector<int> ref = {7, 0, 1, 2, 0, 3, 0, 4};

    workingSet(ref, 3);
}