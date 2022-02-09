#include <iostream>
#include <windows.h>
#include <conio.h>
#include "BackEnd.h"
#include "FrontEnd.h"
using namespace std;
Node* showMenu1(Node* head)
{
    string year, person, win;
    cout << endl;
    cout << "         Enter the year: ";
    cin >> year;
    cout << "         Enter the person the event is connected with: ";
    cin >> person;
    cout << "         Does Bulgaria win the battle? ";
    cin >> win;
    push(&head, year);
    push(&head, person);
    push(&head, win);
    return head;
}
Node* showMenu2(Node* head)
{
    string year, person, win;
    cout << endl;
    cout << "         Enter the year: ";
    cin >> year;
    cout << "         Enter the person the event is connected with: ";
    cin >> person;
    cout << "         Does Bulgaria win the battle? ";
    cin >> win;
    append(&head, year);
    append(&head, person);
    append(&head, win);
    return head;
}
Node* showMenu3(Node* head)
{
    string element;
    cout << endl;
    cout << "         Search for a year or person: ";
    cin >> element;
    search(head, element) ? cout << "Yes, it's there." : cout << "No, it's not there.";
    Sleep(1000);
    return head;
}
Node* showMenu4(Node* head)
{
    string element;
    cout << endl;
    cout << "         Delete an element: ";
    cin >> element;
    deleteNode(&head, element);
    return head;
}

int main()
{
    Node* head = NULL;
    int Set[] = { 7,7,7,7,7,7,7 };
    int counter = 1;
    char key;

    title();

    for (int i = 0;;)
    {

        gotoxy(10, 8);
        color(Set[0]);
        cout << "1. Add a new event in the start of the list";

        gotoxy(10, 10);
        color(Set[1]);
        cout << "2. Add a new event in the end of the list";

        gotoxy(10, 12);
        color(Set[2]);
        cout << "3. Search for a new event";

        gotoxy(10, 14);
        color(Set[3]);
        cout << "4. Delete an event";

        gotoxy(10, 16);
        color(Set[4]);
        cout << "5. Edit an event";

        gotoxy(10, 18);
        color(Set[5]);
        cout << "6. Display the current list";

        gotoxy(10, 20);
        color(Set[6]);
        cout << "7. Exit";
        cout << endl;

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 7))
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 6))
        {
            counter++;
        }
        if (key == '\r')
        {
            if (counter == 1)
            {
                system("cls");
                head = showMenu1(head);
                system("cls");
                title();
            }
            if (counter == 2)
            {
                system("cls");
                head = showMenu2(head);
                system("cls");
                title();
            }
            if (counter == 3)
            {
                system("cls");
                showMenu3(head);
                system("cls");
                title();
            }
            if (counter == 4)
            {
                system("cls");
                head = showMenu4(head);
                system("cls");
                title();
            }
            if (counter == 5)
            {
            }
            if (counter == 6)
            {
                printList(head);
            }
            if (counter == 7)
            {
                return 0;
            }
        }
        Set[0] = 7; Set[1] = 7; Set[2] = 7; Set[3] = 7;  Set[4] = 7; Set[5] = 7; Set[6] = 7;
        if (counter == 1) Set[0] = 12;
        if (counter == 2) Set[1] = 12;
        if (counter == 3) Set[2] = 12;
        if (counter == 4) Set[3] = 12;
        if (counter == 5) Set[4] = 12;
        if (counter == 6) Set[5] = 12;
        if (counter == 7) Set[6] = 12;
    }

}