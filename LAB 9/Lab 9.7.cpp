#include <iostream>
#include <cmath>
using namespace std;

int nextPowerOf2(int x)
{

    int p = 1;

    while (p < x)
        p *= 2;

    return p;
}

int main()
{

    int request;

    cout << "Memory request (KB): ";
    cin >> request;

    int block = nextPowerOf2(request);

    cout << "Allocated block size " << block << " KB" << endl;
}