#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
struct Node {
    string data;
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
void push(Node** head_ref, string new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void append(Node** head_ref, string new_data)
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
bool search(Node* head, string x)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
void deleteNode(Node** head_ref, string key)
{

    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

        delete temp;
    }
}