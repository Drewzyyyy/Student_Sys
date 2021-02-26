#pragma warning(disable:4996)   // For disabling errors caused by localtime 
// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
#include "Util.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <regex>
#include <chrono>

using namespace std;

void Menu(int x) {  // Function that displays outputs
    if (x == 0) {   // Main Menu
        cout << "\tStudent Classification System\n" << endl;
        cout << "  [1] Input a new student" << endl;
        cout << "  [2] Update information" << endl;
        cout << "  [3] Sort List" << endl;
        cout << "  [4] Display all Student Numbers" << endl;
        cout << "  [5] Display an entry" << endl;
        cout << "  [6] Delete an entry" << endl;
        cout << "  [7] Clear linked list" << endl; 
        cout << "  [0] Exit" << endl;
        cout << "Choice: ";
    }
    else if (x == 1) cout << "Invalid input" << endl;   // Any Invalid Outputs
    else if (x == 2) {  // Edit Menu
        cout << "\tWhat do you want to edit\n" << endl;
        cout << "  [1] Student Number" << endl;
        cout << "  [2] Name" << endl;
        cout << "  [3] Course" << endl;
        cout << "  [4] Birthday" << endl;
        cout << "  [5] GWA" << endl;
        cout << "  [0] Return to main menu" << endl;
    }
    else if (x == 3) {
        system("pause");
        system("cls");
    }
    else if (x == 4) {  // Sorting Filter Menu
        cout << "\tSorting Filters\n" << endl;
        cout << "  [1] Student Number" << endl;
        cout << "  [2] Last Name" << endl;
        cout << "  [3] GWA" << endl;
        cout << "  [0] Return to main menu" << endl;
        cout << "Choice: ";
    }
    else if (x == 5) {  // Course Menu
        cout << "\tChoice Courses: " << endl;
        cout << "  [1]  BS Anthropology" << endl;
        cout << "  [2]  BS Architecture" << endl;
        cout << "  [3]  BA Communication and Media Arts" << endl;
        cout << "  [4]  BA English" << endl;
        cout << "  [5]  Diploma in Exercise and Sports Science" << endl;
        cout << "  [6]  Diploma/Master in Urban and Regional Planning" << endl;
        cout << "  [7]  BS Applied Mathematics" << endl;
        cout << "  [8]  BS Biology" << endl;
        cout << "  [9]  BS Computer Science" << endl;
        cout << "  [10] BS Food Technology" << endl;
        cout << "  [11] BS Food Science" << endl;
        cout << "  [12] BS Agribusiness Economics" << endl;
        cout << "  [13] Master in Management" << endl;
        cout << "  [14] PhD by Research" << endl;
    }
}
bool CheckSnum(string snum) {   // Function that checks if the Student Number is viable
    /*if (regex_match(snum, regex("[0-9]{4}-[0-9]{5}"))) return true;
    else return false;*/
    return regex_match(snum, regex("[0-9]{4}-[0-9]{5}"));   // This regular expression returns a true or false if it matches the format
}
string findCourse(int x) {  // Function that returns the enrolled course
    x--;    // Decrements by to match the array index syntax
    switch (x) {
    case 0:
        return "BS Anthropology";
    case 1:
        return "BS Architecture";
    case 2:
        return "BA Communication and Media Arts";
    case 3:
        return "BA English";
    case 4:
        return "Diploma in Exercise and Sports Science";
    case 5:
        return "Diploma/Master in Urban and Regional Planning";
    case 6:
        return "BS Applied Mathematics";
    case 7:
        return "BS Biology";
    case 8:
        return "BS Computer Science";
    case 9:
        return "BS Food Technology";
    case 10:
        return "BS Food Science";
    case 11:
        return "BS Agribusiness Economics";
    case 12:
        return "Master in Management";
    case 13:
        return "PhD by Research";
    default:
        return "None";
    }
}
bool checkBday(int y, int m, int d) {   // Function that checks if the birthday is viable
    m--;    // Decrements by 1 to fit the array index syntax
    bool leap = false;  // Sets the leap year to false
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };    // Array containing all the number of days per month
    if (y % 4 == 0) {   // If-else-if statements that checks if the year is a leap year
        if (y % 100 == 0) {
            if (y % 400 == 0) leap = true;  // Returns true if it matches all criteria to be a leap year
        }
        else leap = true;
    }
    if (leap && m == 1 && d == 29) return true; // If it is a leap year, in february, and the day is 29 then it is a viable birth day
    else if (d > months[m] || d < 1) return false;  // if it exceeds the number of days in that month or if the day is 0 or less then it is not viable
    else return true;   // else if it doesn't violate anything then it is viable
}
Student addStudent(List** hnode) {	// Creates a new student to add to the linked list
    List* head = *hnode;    // Dereferences the head node
    string snum, last, first, mid, crs; // Storage for student number, last name, first name, middle name, and course, respectively
    int y, m, d, c;    // Storage for birth year, birth month, birth day, and chosen course from the course menu
    float g;    // Storage for the GWA
    time_t now = time(0);   // Starts a timer
    tm* ltm = localtime(&now);   // Stops the timer and gets the current time and date now
    int gyear = (1900 + ltm->tm_year)-14;    // Minimum possible year for enrolment

    while (1) {    // Loops to check if the student number is viable and has no copies
        cout << "Input Student Number: ";
        cin >> snum;
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (!CheckSnum(snum)) { // Checks if the format of the student number is correct
            Menu(1);
            continue;
        }
        else if (head->Exists(snum, &head)) {   // Check if the student number is already in the linked list
            cout << "Student already exists" << endl;
            continue;
        }
        break;  // If no violations are met then exits the loop
    }

    while (1) {	// Loops until the correct format of Last Name is entered
            // Proper Student Format according to the Regular Expression: 
            //	Start with a capital letter, then a series of lowercase letters, and 
            //	one dash with the former format (capital then lowercase)
        cout << "\nEnter Last Name/Surname: ";
        cin >> last;
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (regex_match(last, regex("^([A-Z][a-z]+)(-[A-Z][a-z]+)?(\\s(IX|IV|V?I{0,3}))?"))) break;	// If the input is correct exit the loop
        Menu(1);
    }

    while (1) {	// Loops until the correct format of Last Name is entered
            // Proper Student Format according to the Regular Expression: 
            // Start with a capital letter, then a series of lowercase letters, and 
            //	one dash or a space with the former format (capital then lowercase) any number of times
        cout << "\nEnter New First Name/Given Name: ";
        getline(cin, first);
        cin.clear();	// Clears the input buffer
        if (regex_match(first, regex("(^[A-Z][a-z]+)((\\s|-)[A-Z][a-z]*)*"))) break;	// If the input is correct exit the loop
        Menu(1);
    }

    while (1) {	// Loops until the correct format of Middle Name is entered
            // Proper Student Format according to the Regular Expression: 
            //	Start with a capital letter, then a series of lowercase letters, and 
            //	one dash with the former format (capital then lowercase)
        cout << "\nEnter New Middle Name: ";
        cin >> mid;
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (regex_match(mid, regex("^[A-Z][a-z]+(-[A-Z][a-z]+)?"))) break;	// If the input is correct exit the loop
        Menu(1);
    }

    Menu(5);    // Input the chosen course of the student
    while (1) { // Loops until the input is correct
        cout << "\nCourse: ";
        if (!(cin >> c)) {  // If the input is not an integer or a non-roundable float then continues
            cout << "Input error\nPlease Input a number." << endl;
            cin.clear();	// Clears the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
            continue;
        }
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (c < 1 || c>14) Menu(1);    // If the choice is beyond the scope then loops
        else break;  // If no violations are met then exits the loop
    }
    crs = findCourse(c);    // Returns the enrolled course of the student
    fflush(stdin);

    while (1) { // Loops until the birth year is correct
        cout << "\nEnter birth year: ";
        if (!(cin >> y)) {  // If the input is not an integer or a non-roundable float then it continues
            cout << "Input error\nPlease Input a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (y < 1 || y > gyear) Menu(1);    // If the year is beyond the range of 1 or the Current year - 14 then continues
        else break;
    }

    while (1) { // Loops until the birth month is correct
        cout << "\nEnter birth month: ";
        if (!(cin >> m)) {  // If the input is not an integer or a non-roundable float then it continues
            cout << "Input error\nPlease Input a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (m < 1 || m>12) Menu(1);  // If the year is beyond the range of 1 to 12 (January-December) then continues
        else break;
    }

    while (1) { // Loops until the birth day is correct
        cout << "\nEnter birth day: ";
        if (!(cin >> d)) {  // If the input is not an integer or a non-roundable float then it continues
            cout << "Input error\nPlease Input a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (checkBday(y, m, d)) break;  // If it the function returns false, then the format is incorrect, continues
        Menu(1);
    }

    while (1) {  // Loops until the GWA is within the range
        cout << "\nGWA: ";
        if (!(cin >> g)) {  // If the input is not an integer or a non-roundable float then it continues
            cout << "Input error\nPlease Input a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.clear();	// Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Removes the next line
        if (g < 1 || g>5) Menu(1); // If the input is beyond the range of 1 to 5, then continues
        else break;
    }

    Student temp(snum, last, mid, first, crs, y, m, d, g); // Creates a Student object with the following inputs
    return temp;    // Returns the newly created Student object
}