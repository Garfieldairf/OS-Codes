#include <iostream>
#include <cmath>
using namespace std;

class VirtualMemoryCalculator
{
public:
    void calculate(int addressSpace, int pageSize)
    {

        int pages = addressSpace / pageSize;

        int offsetBits = log2(pageSize);

        int pageBits = log2(pages);

        cout << "Pages: " << pages << endl;
        cout << "Offset bits: " << offsetBits << endl;
        cout << "Page bits: " << pageBits << endl;
        cout << "Page table entries: " << pages << endl;
    }
};

int main()
{

    VirtualMemoryCalculator calc;

    int addressSpace;
    int pageSize;

    cout << "Address Space (bytes): ";
    cin >> addressSpace;

    cout << "Page Size (bytes): ";
    cin >> pageSize;

    calc.calculate(addressSpace, pageSize);

    return 0;
}