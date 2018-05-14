#include "LinkedList.h"

#include <iostream>
#include <vector>
#include <ctime>

int main(){
	
	//Create our LinkedList Object
	//and then start adding elements
	

	LinkedList myLinkedList;
 	myLinkedList.printAll();	

	srand(time(NULL));
	//Lets add random values into the LinkedList and the print them out
	std::cout << "\nWe have created our LinkedList";
	std::cout << "\nHow many element should we insert into the LinkedList: ";

	int size;

	std::cin>> size;

	for(int i = 0; i < size ; i++){
		//Random Value Range: [1-50]
		int randomVal = rand()%50 + 1;
		myLinkedList.insert(randomVal);
	}	

	std::cout << "\n\nPrinting values in LinkedList: \n";
	myLinkedList.printAll();

	std::cout << "\n\n";

	//We will now solve the reverse the Linked list
	myLinkedList.reverseTheList(myLinkedList.root);
	
	std::cout << "\n\nPrinting the reversed LinkedList: \n";
	myLinkedList.printAll();
	
	//We will now solve the reverse the Linked list to get back our original LinkedList
	myLinkedList.reverseTheList(myLinkedList.root);

	std::cout <<"\n\nWe will now solve the Merging of Two Linked List problem\n";
	std::cout <<"We will create two Linked List: The original LinkedList and different one.\n";
	
	//Create a copy of the original List
	LinkedList firstList = myLinkedList;

	std::cout <<"\nLinkedList A:\n";
	firstList.printAll();

	//Now create another LinkedList of the same size.
	LinkedList secondList;
	
	for(int j = 0; j < size ; j++){
		//Random Value Range: [1-50]
		int randomVal = rand()%50 + 1;
		secondList.insert(randomVal);
	}

	std::cout <<"\nLinkedList B:\n";
	secondList.printAll();
	std::cout << "\n\nPerforming Merge:\n";

	//We perform the merge by simply connecting the given list with another list.
	firstList.mergingBothLists(secondList.root);

	firstList.printAll();

	std::cout<<"\n\n";


	//We will now solve the detecting a loop in a LinkedList
	//Do we have a loop in the MergedLinked List.
	std::cout << "Do we have a loop in the Merged LinkedList: " << firstList.detectLoop();

	//Create a LinkedList with a loop and the check if we have a loop in the linkedList
	LinkedList loopList;


	loopList.insert(4);
	loopList.insert(9);
	loopList.insert(2);
	loopList.insert(1);
	loopList.insert(66);
	loopList.createLoop();

	std::cout << "\n\n\nWe have created a new LinkedList.\n";

	std::cout << "\nDo we have a loop in the loopList LinkedList: " << loopList.detectLoop();
	std::cout << "\n\n";


}
