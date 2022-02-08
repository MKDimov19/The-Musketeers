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