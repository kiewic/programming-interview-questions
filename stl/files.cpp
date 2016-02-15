#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream readfile;
    ofstream writefile;
    string filename = "myfile.txt";

    readfile.open( filename.c_str() );
    if( readfile )
    {
        // I can read something from the file
        char line[255];
        readfile.getline(line, 255);
        cout << line << endl;
        readfile.close();
    }
    else
    {
        // The file doesn't exist
        writefile.open(filename.c_str());
        // Write something to the file
        writefile << " write some data " << endl;
        writefile.close();
    }

    return 0;
}
