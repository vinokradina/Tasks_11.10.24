#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    HANDLE hNewBuffer, hStdOutOld;
    char buffer[256];
    DWORD dwWritten;

    hNewBuffer = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    if (hNewBuffer == INVALID_HANDLE_VALUE)
    {
        cout << "CreateConsoleScreenBuffer failed." << endl;
        return GetLastError();
    }

    hStdOutOld = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleActiveScreenBuffer(hNewBuffer))
    {
        cout << "SetConsoleActiveScreenBuffer failed." << endl;
        return GetLastError();
    }

    ifstream file("example.txt");
    if (!file)
    {
        cout << "Failed to open file." << endl;
        return 1;
    }

    while (file.getline(buffer, sizeof(buffer)))
    {
        WriteConsole(hNewBuffer, buffer, strlen(buffer), &dwWritten, NULL);
        WriteConsole(hNewBuffer, "\n", 1, &dwWritten, NULL);
    }

    file.close();

    SetConsoleActiveScreenBuffer(hStdOutOld);

    CloseHandle(hNewBuffer);

    return 0;
}