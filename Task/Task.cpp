#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    HANDLE hStdOut;
    WORD attributes[10];
    WORD readAttribute[10];
    DWORD dwWritten, dwRead;
    COORD coord = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwLength = 10;

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
    {
        cout << "Get standard handle failed." << endl;
        return GetLastError();
    }

    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        cout << "Console screen buffer info failed." << endl;
        return GetLastError();
    }

    attributes[0] = BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
    attributes[1] = BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    attributes[2] = BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    attributes[3] = BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    attributes[4] = BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    attributes[5] = BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
    attributes[6] = BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
    attributes[7] = BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    attributes[8] = BACKGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    attributes[9] = BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    if (!WriteConsoleOutputAttribute(hStdOut, attributes, dwLength, coord, &dwWritten))
    {
        cout << "WriteConsoleOutputAttribute failed." << endl;
        return GetLastError();
    }

    if (!ReadConsoleOutputAttribute(hStdOut, readAttribute, dwLength, coord, &dwRead))
    {
        cout << "ReadConsoleOutputAttribute failed." << endl;
        return GetLastError();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Attribute " << i << ": " << readAttribute[i] << endl;
    }

    cout << "Press any key to exit.";
    cin.get();

    return 0;
}