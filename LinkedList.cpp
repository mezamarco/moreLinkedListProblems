#include "LinkedList.h"


LinkedList::LinkedList(){

	nodeCounter = 0;
	root = nullptr;
}



bool LinkedList::insert(int num){
	
	//If the Root points to nothing then all it to the root
	if(root == nullptr){
		//Create a new Node and then place make the root point to it
		
		Node* newerNode = new Node(num);
	        root = newerNode;	
		return 1;
	}	

	//Traverse to the end of the LinkeList and then place it in the end
	//Starting in the root node
	Node* current  = root;

	while(current->nextPtr != nullptr){
		current = current->nextPtr;
	}
	//We are now now in the last node and 
	//we have to make this node point to the newly created element
	Node* newerNode = new Node(num);

	current->nextPtr = newerNode;
	return 1;
}
	

void LinkedList::printAll(){
	if(root == nullptr){
		std::cout <<"\n\nEmpty List\n\n";

	}

	Node* current = root;
	
	while(current != nullptr)
	{
		std::cout << current->value << "  ";
		current = current->nextPtr;
	}


	return;
}

//First problem: Reverse a LinkedList
void LinkedList::reverseTheList(Node* head){
	
	if(head == nullptr){
		std::cout << "\nEmpty List and therefore we cannot reverse the linkedList\n\n";
		return;
	}
	//Iterate thorugh all the element in the LinkedList
	//Start at the root node
	Node* current =  head;


	std::stack<int> myStack;
	while(current){
		//Place all the element into the stack
		myStack.push(current->value);
		
		current = current->nextPtr;	
	}
	

	//Using the stack go through the LinkedList and then rewrite the values
	//Start at the root;
	
	Node* tracker = head;
	while(!myStack.empty()){
		
		tracker->value = myStack.top();
		myStack.pop();
		tracker = tracker->nextPtr;
	}
	return;
}

//Second problem: Merge Two LinkedLst, simply merge listB into listA
void LinkedList::mergingBothLists(Node* head){


	//Go to the end of the current list and then make the connection to the other List
	
	Node* current = root;

	while(current->nextPtr != nullptr){
	
		current = current->nextPtr;

	}

	//We are in the last node of the current List
	//Now make the connection to other list
	current->nextPtr = head;

	//We have made the connection and now we can return
	
	return;

}
	
void LinkedList::createLoop(){

	// Starting at the end of the list I will create a loop.
	Node* current = root;

	//Store an address and then create the loop
	//you need to make multiple nodes in order to form the loop
	int counter = 0;
	Node* repeatNode;

	while(current->nextPtr){

		current = current->nextPtr;
		++counter;
		
		if(counter == 2)
		{
			//Store this address
			repeatNode = current;
		}
	}

	//We are at the end of the last node make it point to new Node
	Node* middleNode = new Node(1000);
	current->nextPtr = middleNode;

	middleNode->nextPtr = repeatNode;

	return;
}



bool LinkedList::detectLoop(){


	//Initialize two pointers , start and finish, move start 1 step and move finish 2 times
	//If start value and finish value are the same then we have a loop
	

	//Starting at the root
	Node* start = root;
	Node* finish = root;

	while(finish) 
	{	
		if(finish->nextPtr == nullptr){
			return 0;
		}
		

		
		//Make the moves
		start = start->nextPtr;
		finish = finish->nextPtr->nextPtr;

		if(finish == nullptr){
			return 0;
		}

		std::cout << "\nS: "<< start->value << "   F: " << finish->value;

		if(start->value == finish->value){
			return 1;
		}
	
	
	}


	
	//We have reached the end of the linkedList and we did not find a loop
	return 0;

}
