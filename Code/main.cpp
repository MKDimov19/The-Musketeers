#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insertAfter(Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();

    Node* last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}
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