#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void title()
{
    cout << ".-..-.            .-.          .-.                        " << endl;
    cout << ": `' :            : :.-.      .' `.                       " << endl;
    cout << ": .. :.-..-. .--. : `'.' .--. `. .' .--.  .--. .--.  .--. " << endl;
    cout << ": :; :: :; :`._-.': . `.' '_.' : : ' '_.'' '_.': ..'`._-.'" << endl;
    cout << ":_;:_;`.__.'`.__.':_;:_;`.__.' :_; `.__.'`.__.':_;  `.__.'" << endl;
}
void showMenu1()
{

}