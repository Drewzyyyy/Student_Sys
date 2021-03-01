# Student_Sys 
#Simple OOP Project by using two objects Student and List
#Student stores the data, such as the Name, Student Number, etc.
#It also stores all the methods and the like

#List stores the data in a singly linked list
#It also stores all the methods for editing the data 
#It is originally sorted by Student Number (XXXX-XXXXX), but can be modified by
#   General Weighted Average (GWA) + Last Name, and Last Name + First Name
#It is sorted using the C++ Map (Red-Black Tree)
#The Key-Value pair is the sorting key (Student Number, GWA+Last, Last+First) and address of the current node
#Access the Map then get then iterate through it, getting the address and connecting them starting with the head node
