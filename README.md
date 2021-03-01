# Student System using Singly Linked List
Simple OOP Project by using two objects *Student and List*

## *Student*
- Stores the data, such as the Name, Student Number, etc.
- Stores all the methods asuch as edit, check, getters and setters

## *List* 
- Stores the data in a singly linked list
- It also stores all the methods for editing the data
- It is originally sorted by Student Number (XXXX-XXXXX), but can be modified by _General Weighted Average (GWA) + Last Name, and Last Name + First Name.
- It is sorted using the C++ Map (Red-Black Tree).
  - The Key-Value pair is the sorting key (Student Number, GWA+Last, Last+First) and address of the current node
  - Access the Map then get then iterate through it, getting the address and connecting them starting with the head node
