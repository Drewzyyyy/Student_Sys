#pragma once
#include "Student.h"
#include "List.h"
// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
using namespace std;

void Menu(int x);	// Function that displays outputs
bool CheckSnum(string snum);	// Function that checks if the Student Number is viable
string findCourse(int x);	// Function that returns the enrolled course
bool checkBday(int y, int m, int d);	// Function that checks if the birthday is viable
Student addStudent(List** hnode);	// Creates a new student to add to the linked list