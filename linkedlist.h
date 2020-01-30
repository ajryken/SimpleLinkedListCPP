#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class LinkedList
{
	public:
	node* head;
	
	void insert(int d, int index);
	void remove(int index);
	void print();

	LinkedList();
};

//CONSTRUCTOR
LinkedList::LinkedList()
{
	head = nullptr;
}

//INSERTS NODE INTO LINKED LIST
void LinkedList::insert(int d, int index)
{
	node* newNode = new node;
	newNode->data = d;
	newNode->next = nullptr;
	
	if(head == nullptr && index == 0) head = newNode;												
	else if(index == 0)																				
	{
		newNode->next = head;
		head = newNode;
	}
	else if(index > 0)																				
	{
		node* step = head;
		int c = 0;
		while(c < index-1 && step != nullptr)
		{
			step = step->next;
			c++;
		}
		if(step != nullptr)																			
		{
			newNode->next = step->next;
			step->next = newNode;
		}
		else cout << "Index out of bounds (Too high). Try again." << endl;							
	}
}

//REMOVES NODE FROM LINKED LIST
void LinkedList::remove(int index)
{
	node* delPtr = head;
	if(head == nullptr && index == 0) cout << "No list exists. Try again." << endl;					
	else if(index == 0)																				
	{
		head = head->next;
		delete delPtr;
	}
	else if(index > 0)
	{
		node* step = head;
		int c = 0;
		while(c < index-1 && step != nullptr)														
		{
			step = step->next;
			c++;
		}
		if(step != nullptr)																			
		{
			delPtr = step->next;
			step->next = delPtr->next;
			delete delPtr;
		}
		else cout << "Index out of bounds (Too high). Try again." << endl;							
	}
	else if(index < 0) cout << "Index out of bounds (Too low). Try again." << endl;					
}

//PRINTS THE LINKED LIST
void LinkedList::print()
{
	node* step = head;
	if(head == nullptr)
	{
		cout << "(Empty)" << endl;
		return;
	}
	while(step != nullptr)
	{
		cout << step->data << '\t';																	
		step = step->next;																			
	}
	cout << endl;
}

#endif