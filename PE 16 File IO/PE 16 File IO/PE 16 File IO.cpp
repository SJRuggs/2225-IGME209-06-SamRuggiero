#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("test.txt");

    if (outFile.is_open())
    {
        outFile << "Example output\n";
        outFile << "Another Line\n";
        outFile.close();
    }

    ifstream inFile;

    inFile.open("test.txt", ios::binary);

    if (inFile.is_open())
    {
        // seek and get the length
        inFile.seekg(0, ios::end);
        int length = (int)inFile.tellg();

        // seek back to start
        inFile.seekg(0, ios::beg);

        // make an array to hold the file
        char* fileContents = new char[length + 1];

        // read the file and set null pointer
        inFile.read(fileContents, length);
        fileContents[length] = 0;

        // close file
        inFile.close();

        string str;
        str.assign(fileContents, length);

        delete[] fileContents;

        cout << str;
    }
}