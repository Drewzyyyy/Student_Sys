// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
#include <iostream>
#include <stdlib.h>
#include "Student.h"
#include "List.h"
#include "Util.h"

using namespace std;

int main() {
	List* head = new List();	// Create a head node for the list
	int x = 0;	// Choice variable
	string temp = "";	// Temporary variable for string inputs
	while (1) {	// Loops the entire program
		system("cls");	// Clears the console
		Menu(0);	// Displays the main menu
		if (!(cin >> x)) {	// Continues if the input is not an integer or a non-roundable float
			cout << "Input error\nPlease Input a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (x == 1) {	// Inserts a new student to the list
			head->Insert(addStudent(&head), &head);
			Menu(3);	// Pause then clears the console
		}
		else if (x == 2) {	// Edits an entry in the list
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			do {	// Loops when the student number format is wrong
				cout << "\nEnter Student Number: ";
				cin >> temp;
				cin.clear();	// Clears the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
				if (!CheckSnum(temp)) Menu(1);
				else if (!(head->Exists(temp,&head))) Menu(1);
				else break;
			} while (1);	// If a false is returned then continue the loop
			head->Edit(temp,&head);	// Edit the entry with the student number
			Menu(3);	// Pause then clears the console
		}
		else if (x == 3) {	// Sorts all entries in the list
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			Menu(4);	// Displays the sorting menu
			while (1) {	// Loops until the user inputs the proper format
				cout << "Choice: ";
				if (!(cin >> x)) {	// Continues if the input is not an integer or a non-roundable float
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				break;
			}
			head->Sort(x, &head);	// Sort the list to the user's preference
			Menu(3);	// Pause then clears the console
		}
		else if (x == 4) {	// Displays all entries
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			head->DisplayAll(&head);	// Method to display all entries
			Menu(3);	// Pause then clears the console
		}
		else if (x == 5) {	// Displays a specific entry in the linked list
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			do {	// Loops when the student number format is wrong
				cout << "\nEnter Student Number: ";
				cin >> temp;
			} while (!CheckSnum(temp));	// If a false is returned then continue the loop
			head->Display(temp, &head);	// Display the corresponding student's data
			Menu(3);	// Pause then clears the console
		}
		else if (x == 6) {	// Deletes a specific entry in the linked list
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			do {	// Loops when the student number format is wrong
				cout << "\nEnter Student Number: ";
				cin >> temp;
			} while (!CheckSnum(temp));	// If a false is returned then continue the loop
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			head->Delete(temp, &head);	// Deletes the chosen student with the corresponding student number
			Menu(3);	// Pause then clears the console
		}
		else if (x == 7) {	// Clears the entire linked list
			if (head->next == NULL) {	// If the head is empty, meaning the list is empty
				cout << "List is Empty!" << endl;
				Menu(3);	// Pause then clears the console
				continue;
			}
			head->Clear(&head);	// Method to clear the entire list
			cout << "\nList has been cleared." << endl;
			Menu(3);	// Pause then clears the console
		}
		else if (x == 0) {	// Exits the program
			cout << "Exiting Program...";
			break;
		}
	}
	return 0;
}