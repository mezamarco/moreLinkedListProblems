#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <stack>

class LinkedList{
	
public:
	int nodeCounter;
	Node* root;

	LinkedList();
	~LinkedList();

	bool insert(int num);
	void printAll();

	


	//We will solve three problem using linked list
	

	//First problem: Reverse a LinkedList
	void reverseTheList(Node* head);

	//Second problem: Merge Two LinkedLst, simply merge listB into listA
	void mergingBothLists(Node* head);
	
	//Third Problem: Find a loop in a LinkedList
	bool detectLoop();
	

	///Create a loop;
	void createLoop();

	//We delete all the nodes using a static helper function, becasue we are deleting nodes
	//not this LinkedList itself
	static void deleteAll(Node* root);

};

#endif
