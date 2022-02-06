#include <iostream>
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
    void Menu()
    {
        cout << "                                                  HISTORY SEARCHER\n";
        cout << endl;
        cout << "                                          Press 1 to search an event by date\n ";
        cout << endl;
        cout << "                                          Press 2 to search an event by name\n";
        cout << endl;
        cout << "                                          Press 3 to enter an event in the database\n";
        cout << endl;
        cout << "                                          Press 4 to exit the program\n";
        cout << endl;

    }
 