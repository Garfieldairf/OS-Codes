#include <iostream>
#include <fstream>
using namespace std;

const int PAGE_SIZE = 4096;

int main()
{

    ifstream file("test.txt");

    string text((istreambuf_iterator<char>(file)),
                istreambuf_iterator<char>());

    int pages = text.size() / PAGE_SIZE + 1;

    cout << "File size " << text.size() << endl;
    cout << "Pages " << pages << endl;

    int offset;

    cout << "Enter offset to read: ";
    cin >> offset;

    int page = offset / PAGE_SIZE;

    cout << "Loading page " << page << endl;

    cout << "Character: " << text[offset] << endl;
}