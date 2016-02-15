#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool myComparison(char* a, char* b)
{
    cout << "comparing ..." << endl;
    return strcmp(a, b) < 0;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    cout << "sorting ..." << endl;
    sort(argv, argv + argc, myComparison);

    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    return 0;
}
