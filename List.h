#pragma once
#include <iostream>
#include "Student.h"

using namespace std;

class List{	// This class creates a Linked List of every Student
	public:
		Student data;	// Class that stores the data of the current Student node
		List* next;	// Next Student Node

		// Constructor

		List();

		//	Linked List Utility Methods 

		int Count(List** hnode); // Method that counts the nodes in the Linked List
		void Insert(Student info, List** hnode);	// Method that inserts a new node(or a new Student) to the Linked List
		void Delete(string snum, List** hnode);	// Method that removes a node from the Linked List by finding the student number
		void Clear(List** hnode);	// Method that clears or removes all nodes from the Linked List
		void Display(string snum, List** hnode);	// Method that displays the selected node using the Student Number
		void DisplayAll(List** hnode);	// Method that displays all info about all Students
		void Edit(string snum, List** hnode);	// Method that edits the Student's info
		void Sort(int x, List** hnode); // Methods that sorts the entire Linked List according to the user's preference (default is Student Number)
		bool Exists(string snum, List** hnode);	// Method that checks if that node exists
};

