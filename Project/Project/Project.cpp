#include <iostream>
#include <windows.h>
#include <conio.h>
#include "BackEnd.h"
#include "FrontEnd.h"
using namespace std;

int main()
{
    int Set[] = { 7,7,7 };
    int counter = 2;
    char key;

    for (int i = 0;;)
    {
        key = _getch();
        gotoxy(10, 5);
        color(Set[0]);
        cout << "1. Menu";

        gotoxy(10, 6);
        color(Set[1]);
        cout << "2. Help";

        gotoxy(10, 7);
        color(Set[2]);
        cout << "3. Help";

        if (key == 72 && (counter >= 2 && counter <= 3))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2))
        {
            counter++;
        }
        if (key == '\r')
        {
            if (counter == 1)
            {
                cout << "Menu 1 is Open";
            }
            if (counter == 2)
            {
                cout << "Menu 2 is Open";
            }
            if (counter == 3)
            {
                cout << "Menu 3 is Open";
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        if (counter == 1)
        {
            Set[0] = 12;
        }
        if (counter == 2)
        {
            Set[1] = 12;
        }
        if (counter == 3)
        {
            Set[2] = 12;
        }
    }
    return 0;
}