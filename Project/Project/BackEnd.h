#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sstream>
using namespace std;

struct Event {
	string year;
	string person;
	bool isWinForBulgaria;

	void print() {
		cout << "Year " << year << "; Related to " << person << "; " << (isWinForBulgaria ? "Bulgaria wins" : "Bulgaria loses") << endl;
	}
};
struct Node {
	string grayCodeId;
	//string data;
	Event data;
	struct Node* next;
};

//this is not used for now but might be useful
int stringToInt(string value) {
	stringstream intValue(value);
	int number = 0;
	intValue >> number;

	return number;
}

//convert the int to binary
string intToBinary(int number) {
	string result = "";
	while (number!=0)
	{
		result = (number % 2 == 0 ? "0" : "1") + result;
		number /= 2;
	}
	return result;
}

// Helper function to xor two characters
char xor_c(char a, char b) { return (a == b) ? '0' : '1'; }

// Helper function to flip the bit
char flip(char c) { return (c == '0') ? '1' : '0'; }

// function to convert binary string
// to gray string
string binaryToGray(string binary)
{
	string gray = "";

	// MSB of gray code is same as binary code
	gray += binary[0];

	// Compute remaining bits, next bit is computed by
	// doing XOR of previous and current in Binary
	for (int i = 1; i < binary.length(); i++) {
		// Concatenate XOR of previous bit
		// with current bit
		gray += xor_c(binary[i - 1], binary[i]);
	}

	return gray;
}

// function to convert gray code string
// to binary string
string grayToBinary(string gray)
{
	string binary = "";

	// MSB of binary code is same as gray code
	binary += gray[0];

	// Compute remaining bits
	for (int i = 1; i < gray.length(); i++) {
		// If current bit is 0, concatenate
		// previous bit
		if (gray[i] == '0')
			binary += binary[i - 1];

		// Else, concatenate invert of
		// previous bit
		else
			binary += flip(binary[i - 1]);
	}

	return binary;
}

int binaryToInt(string binary) {
	return stoi(binary, 0, 2);
}

int nextId = 1;

void printList(Node* node)
{
	while (node != NULL)
	{
		int nodeID = binaryToInt(grayToBinary(node->grayCodeId));
		cout << "#" << nodeID << ". ";
		node->data.print();
		node = node->next;
	}
}
void push(Node** head_ref, Event new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->grayCodeId = binaryToGray(intToBinary(nextId));
	(*head_ref) = new_node;
	nextId++;
}
void append(Node** head_ref, Event new_data)
{
	Node* new_node = new Node();

	Node* last = *head_ref;

	new_node->data = new_data;

	new_node->next = NULL;

	new_node->grayCodeId = binaryToGray(intToBinary(nextId));

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		nextId++;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	nextId++;
	return;
}
bool search(Node* head, string x)
{
	Node* current = head;
	while (current != NULL)
	{
		if (current->data.year == x || current->data.person == x)
			return true;
		current = current->next;
	}
	return false;
}
void deleteNode(Node** head_ref, int id)
{
	Node* temp = *head_ref;
	Node* prev = NULL;

	if (temp != NULL && temp->grayCodeId == binaryToGray(intToBinary(id)))
	{
		*head_ref = temp->next;
		delete temp;
		return;
	}
	else
	{
		while (temp != NULL && temp->grayCodeId != binaryToGray(intToBinary(id)))
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