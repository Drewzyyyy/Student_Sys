#pragma warning(disable:4996)	// For disabling errors caused by localtime 
// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
#include "List.h"
#include "Student.h"
#include "Util.h"
#include <chrono>
#include <regex>
#include <map>
using namespace std;

// Constructor

List::List() {
	this->next = NULL;
}

// Linked List Utility Methods

int List::Count(List** hnode) { // Method that counts the nodes in the Linked List
	List* head = *hnode;	// Dereferences the head node 
	head = head->next;	// Moves to the first node, the head node is pointing to
	if (head == NULL) {	// Checks if the Linked List is empty before counting
		cout << "List is empty!" << endl;
		return 0;
	}
	int count = 0;	// Creates a counter node
	while (head != NULL) {	// Loops through the entire linked list until the current node is NULL
		count++;	// Increment the counter each node that is not NULL
		head = head->next;	// Moves the node to the next node
	}
	return count;	// Return the final count of the nodes
}
void List::Insert(Student info, List** hnode) {	// Method that inserts a new node(or a new Student) to the Linked List
	List* newnode = new List;	// Creates a new node 
	newnode->data = info;	// Inserts the new Student into the data attribute
	newnode->next = NULL;	// Sets the previous and next attributes to NULL
	List* head = *hnode;	// Dereferences the head node 
	if (head->next == NULL) head->next = newnode;	// If the list is empty, set the newnode as the head and tail
	else {	// If the list is not empty insert the new node to the back, and sort by Student Number
		while (head->next != NULL) head = head->next;	// Loops until the last node
		head->next = newnode;	// Insert to the next of the last node
		Sort(1,*(&hnode));	// Sort by student number
	}
}
void List::Delete(string snum, List** hnode) {	// Method that removes a node from the Linked List by finding the student number
	List* head = *hnode;	// Dereferences the head node 
	if (!(head->Exists(snum, &head))) {	// If the student number does not exist then return
		cout << "Student does not exist" << endl;
		return;
	}
	List* prev = head;	// Copy of the head node for removal of the previous node
	head = head->next;	// Moves the head node to the first node
	while (head != NULL) {	// Loops the entire Linked List until the head is equal to the tail
		/* The process of the removal of node:
		*	Linked List: (Remove 2019)
		*		2018 <-> 2019 <-> 2020 ;		Check if the current Student number is 2019
		*		2018 <-> 2020 ; 2019			The next node of 2019 is now 2020, and the previous node of 2020 is 2019
		*		2018 <-> 2020 ;					Deleted 2019; this is the final linked list
		*/
		if (snum == head->data.getSnum()) {	// True if the student number matches the next node's student number
			prev->next = head->next;	// The next node of the previous node is the next node
			cout << "\nRemoved student: " << head->data.getName() << " successfully" << endl;
			delete head;	// Remove the memory allocation of the current node
			return;
		}
		prev = head;	// Sets the prev node as the current node
		head = head->next;	// Moves the head node to the next node
	}
}
void List::Clear(List** hnode) {	// Method that clears or removes all nodes from the Linked List
	List* head = *hnode;	// Dereferences the head node 
	List* prev = head;	// Copy of the head node
	head = head->next;	// Move the head node to the first node
	while (prev->next != NULL) {	// Loops the Linked List until the tail node is NULL
		prev->next = head->next;	// Sets the next node of the prev or head node as the next node of the next node
		delete head;	// Remove the current node 
		head = prev->next;	// Set the current node as the node the head node is connected in
	}
	/* The main concept of how this works is maintaining the head node ('prev') stagnant while the traversing head node connects the next nodes
	*	Prev (head) -> Node 1 -> Node 2 -> Node 3 -> NULL	; (Isolated nodes/Removed nodes here)
	*	Prev (head)	-> Node 2 -> Node 3 -> NULL				; Node 1
	*	Prev (head)	-> Node 3 -> NULL						; Node 1, Node 2
	*	Prev (head)	-> NULL									; Node 1, Node 2, Node 3
	*/
}
void List::Display(string snum, List** hnode) {	// Method that displays the selected node using the Student Number
	List* head = *hnode;	// Dereferences the head node 
	head = head->next;	// Sets the head node as the first node
	while (head != NULL) {	// Loops the entire linked list until the head and tail are equal
		if (head->data.getSnum() == snum) {	// True if the Student Number to be searched is the same as the current node's Student number
			cout << "Student Number: " << head->data.getSnum() << endl;	// Displays all info about the Student
			cout << "Name: " << head->data.getName() << endl;
			cout << "Course: " << head->data.getCourse() << endl;
			cout << "Year Level: " << head->data.getSen() << endl;
			cout << "Birthday: " << head->data.getBday() << endl;
			cout << "Age: " << head->data.getAge() << endl;
			cout << "GWA: " << head->data.getGWA() << endl;
			cout << "Current Standing: " << head->data.getStand() << endl;
			return;
		}
		head = head->next;	// Moves the nodes to the next node
	}
}
void List::DisplayAll(List** hnode) {	// Method that displays all info about all Students
	List* head = *hnode;	// Dereferences the head node
	head = head->next;	// Sets the head node as the first node
	while (head != NULL) {	// Loops the entire Linked List until the current node is NULL
		cout << "Student Number: " << head->data.getSnum() << endl;	// Displays all info about the Student
		cout << "Name: " << head->data.getName() << endl;
		cout << "Course: " << head->data.getCourse() << endl;
		cout << "Year Level: " << head->data.getSen() << endl;
		cout << "Birthday: " << head->data.getBday() << endl;
		cout << "Age: " << head->data.getAge() << endl;
		cout << "GWA: " << head->data.getGWA() << endl;
		cout << "Current Standing: " << head->data.getStand() << "\n" << endl;
		head = head->next;	// Move to the next node
	}
}
void List::Edit(string snum, List** hnode) {
	List* head = *hnode;	// Dereferences the head node
	head = head->next;	// Sets the first node as the head node
	while (head->data.getSnum() != snum) head = head->next;	// Loops the entire Linked List until the Student is found
	int x = 0;	// Choice Variable
	Menu(2);	// Displays the text for editing the entry
	while (1) {	// Error loop if the input is incorrect (not an integer)
		cout << "Choice: ";
		if (!(cin >> x)) {	// Returns an error if the input is not an integer or a non-roundable float
			cout << "Input error\nPlease input a number";
			cin.clear();	// Clears the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
		}
		else break;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string temp_s;	// Temporary storage for the new string inputs (Student Number, Name, etc.)
	float temp_f = 0;	// Temporary storage for the new GWA
	if (x == 0) return;	// Exit the Editing Menu
	else if (x == 1) {	// Change the Student Number of the selected Student
		cout << "\tCurrent Student Number: " << snum << endl;
		cout << "Enter new Student Number for "<<head->data.getName()<<": " << endl;
		while (1) {	// Loops until the correct format of Student Number is entered
			// Proper Student Number format according to its Regular Expression: [0-9]{4}-[0-9]{5}
			// Can be translated as: 0000-00000 (Note: The 0 can be any number from 0-9)
			cout << "Enter new Student Number for " << head->data.getName() << ": " << endl;
			cin >> temp_s;
			if (!CheckSnum(temp_s)) Menu(1);	// If the format is incorrect then it throws an error
			else if (head->Exists(temp_s,&head))cout << "Student already exists" << endl;	// If the Student Number exists, throws an error
			else break;	// Exits the loop if no error has occurred
		}
		head->data.setSnum(temp_s);	// Set the Student Number in the current node's data
		head->data.findSen(head->data.getSen());	// Also set the seniority of the Student
	}
	else if (x == 2) {	// Change the Name of the selected Student
		cout << "\tCurrent Name: " << head->data.getName() << endl;
		while (1) {	// Loops until the correct format of Last Name is entered
			// Proper Student Format according to the Regular Expression: 
			//	Start with a capital letter, then a series of lowercase letters, and 
			//	one dash with the former format (capital then lowercase)
			cout << "\nEnter New Last Name/Surname: ";
			cin >> temp_s;
			cin.clear();	// Clears the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
			if (regex_match(temp_s, regex("^([A-Z][a-z]+)(-[A-Z][a-z]+)?(\\s(IX|IV|V?I{0,3}))?"))) {	// If the input is correct exit the loop
				head->data.setLast(temp_s);	// Enter the new last name in the student's data
				break;
			}
			Menu(1);	// Error output
		}

		while (1) {	// Loops until the correct format of First Name is entered
			// Proper Student Format according to the Regular Expression: 
			// Start with a capital letter, then a series of lowercase letters, and 
			//	one dash or a space with the former format (capital then lowercase) any number of times
			cout << "\nEnter New First Name/Given Name: ";
			getline(cin, temp_s);
			cin.clear();	// Clears the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
			if (regex_match(temp_s, regex("(^[A-Z][a-z]+)((\\s|-)[A-Z][a-z]*)*"))) {	// If the input is correct exit the loop
				head->data.setFirst(temp_s);	// Enter the new first name in the student's data
				break;
			}
			Menu(1);	// Error output
		}

		while (1) {	// Loops until the correct format of Middle Name is entered
			// Proper Student Format according to the Regular Expression: 
			//	Start with a capital letter, then a series of lowercase letters, and 
			//	one dash with the former format (capital then lowercase)
			cout << "\nEnter New Middle Name: ";
			cin >> temp_s;
			cin.clear();	// Clears the input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
			if (regex_match(temp_s, regex("^[A-Z][a-z]+(-[A-Z][a-z]+)?"))) {	// If the input is correct exit the loop
				head->data.setMid(temp_s);	// Enter the new first name in the student's data
				break;
			}
			Menu(1);	// Error output
		}
	}
	else if (x == 3) {	//Change the enrolled course of the student
		cout << "\tCurrent Enrolled Course: " << head->data.getCourse() << endl;
		Menu(5);	// Displays all courses available in UP Mindanao
		do {	// Loops until the input is correct
			cout << "Choice: ";
			if (!(cin >> x)) {	// Throws an error if the input is not an integer
				cout << "Input error\nPlease input a number";
				cin.clear();	// Clears the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the newline character
				continue;
			}
			fflush(stdin);	// Clears the input buffer
			if (x < 1 || x>14) Menu(1);	// If outside the range of the possible inputs then continue the loop
			else break;
		} while (1);	
		head->data.setCourse(findCourse(x));	// Enter the new enrolled course in the student's data 
	}
	else if (x == 4) {	// Change the birthday of the student
		time_t now = time(0);   // Starts a timer
		tm* ltm = localtime(&now);  // Stops the timer and gets the current time and date now
		int cutoff = (1900 + ltm->tm_year)-17;    // Get the current year
		int y = 0, m = 0, d = 0;	// Year, Month, and Day of birth date
		cout << "\tCurrent Birthday Listed: " << head->data.getBday() << endl;
		do {	// Loops until the year is in correct format
			cout << "\nEnter New Birth Year in decimal form: ";
			if (!(cin >> y)) {	// Throws an error if the input is not an integer
				cout << "Input error\nPlease input a number";
				cin.clear();	// Clears the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the newline character
			}
			if (y<1 || y>cutoff) Menu(1);	// If outside the range of the possible inputs then continue the loop
			else break;
		} while (1);	// The student must atleast be 17 years old
		do {	// Loops until the month is in correct format
			cout << "\nEnter New Birth Month in decimal form: ";
			if (!(cin >> m)) {	// Throws an error if the input is not an integer
				cout << "Input error\nPlease input a number";
				cin.clear();	// Clears the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the newline character
			}
			if (m < 1 || m>12) Menu(1);	// If outside the range of the possible inputs then continue the loop
			else break;
		} while (1);	// The lower bounds of the month is 1 or January, and the upper bound is 12 or December 

		do {	// Loops until the day is in correct format
			cout << "\nEnter New Birth Day in decimal form: ";
			if (!(cin >> d)) {	//
				cout << "Input error\nPlease input a number";
				cin.clear();	// Clears the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the newline character
			}
			if (!checkBday(y, m, d)) Menu(1);	// Checks if the Birth day is viable (leap year), and continues if it is not viable
			else break;
		} while (1);	// No need for bounds since the value is checked in the checkBday function 
		head->data.setBday(y,m,d);	// Enter the new birthday in the student's data
		head->data.setAge(head->data.findAge(y,m,d));	// Enter the new age of the student in his/her data
	}
	else if (x == 5) {	// Change the GWA of the student
		cout << "\tCurrent GWA: " << head->data.getGWA() << endl;
		do {	// Loops until the GWA is within bounds
			cout << "Enter new GWA: ";
			if (!(cin >> temp_f)) {
				cout << "Input error\nPlease Input a number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (temp_f < 1 || temp_f>5) Menu(1);	// If outside the range of the possible inputs then continue the loop
			else break;
		} while (1);
		head->data.setGWA(temp_f);	// Enter the new GWA in the student's data
		head->data.setSen(head->data.getStand());	// Enter the new seniority of the student in his/her data
	}
}
void List::Sort(int x, List** hnode) {	// Sorting the Student List according to user preference
	List* head = *hnode;	// Dereferences the head node
	List* other = head;	// Creates a copy of the head node
	multimap<string, List*> tree;	// Creates a multimap that stores the order of the user-defined sorting method
	while (other != NULL) {	// Loops the entire Linked List
		/* Since multimap automatically orders the keys, when you input the specific data as student number, 
		*  the data is already ordered, each entry should have a key-element comination of the order method 
		*  (Student number, Last Name + First Name, GWA + First Name) and the pointer of the node
		*  Example: Input Key-Element                        | Output Key-Element
		*               00025-*Address of Student 1          |      00003-*Address of Student 2
		*               00003-*Address of Student 2          |      00005-*Address of Student 4
		*				00011-*Address of Student 3			 |      00011-*Address of Student 3
		*				00005-*Address of Student 4          |		00025-*Address of Student 1
		*	The example shows that the data is ordered using the keys, thus we only need to connect the elements
		*/
		if (x == 1) tree.insert(pair<string, List*>(other->data.getSnum(), other));	// Orders by Student Number (default)
		else if(x==2) tree.insert(pair<string, List*>(other->data.getLastFirst(), other));	// Orders by Last Name + First Name
		else if(x==3) tree.insert(pair<string, List*>(other->data.getGWALast(), other));	// Orders by GWA + Last Name
		other = other->next;	// Moves to the next node
	}
	for (auto i = tree.begin(); i != tree.end(); i++) {	// Loops the entire multimap until the hypothetical last node is reached
		head->next = i->second;	// Sets the head node as the current key-element
		head = head->next;	// Move to the next node
	}
	tree.clear();	// Removes the tree
	head->next = NULL;	// Sets the last node's next as NULL
}
bool List::Exists(string snum, List** hnode) {	// Method that checks if that node exists
	List* head = *hnode;	// Dereferences the head node
	if (head == NULL) return false;	// If the List is empty returns 0 or false
	else {
		while (head != NULL) {	// Loops the entire linked list until the current node is NULL
			if (head->data.getSnum() == snum) return true;	// If the current node's student number matches the snum, then return 1 or true
			head = head->next;	// Move to the next node
		}
		return false;	// Else if not found the return 0 or false
	}
}
