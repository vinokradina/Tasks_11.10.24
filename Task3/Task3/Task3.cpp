#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printFile(const char* fileName, bool suppressErrors)
{
    ifstream file(fileName);
    if (!file)
    {
        if (!suppressErrors)
        {
            cerr << "Error: File " << fileName << " not found." << endl;
        }
        return;
    }

    char buffer[256];
    while (file.getline(buffer, sizeof(buffer)))
    {
        cout << buffer << endl;
    }
    file.close();
}

int main()
{
    bool suppressErrors = false;
    vector<string> fileNames = { "file1.txt", "file2.txt", "file3.txt" };

    for (const auto& fileName : fileNames)
    {
        printFile(fileName.c_str(), suppressErrors);
    }

    return 0;
}