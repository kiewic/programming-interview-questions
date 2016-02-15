#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    std::string str1("./a.out");
    std::string str2(argv[0]);
    std::hash<std::string> str_hash;
    cout <<
        str1 <<
        " vs " <<
        str2 <<
        " is " <<
        (str_hash(str1) == str_hash(str2)) <<
        endl;

    return 0;
}
