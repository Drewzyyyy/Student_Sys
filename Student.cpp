#pragma warning(disable:4996)   // For disabling errors caused by localtime 
// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
#include <string>
#include <chrono>
#include "Student.h"

using namespace std;

// Constructors

Student::Student() {
    // Inputed values are inserted directly to the attributes
    this->student_number = "";
    this->lName = "";
    this->mName = "";
    this->fName = "";
    this->course = "";
    this->year = 0;
    this->month = 0;
    this->day = 0;
    this->gwa = 0;
    // Calculated values are calculated using utility methods, then inserted to the attributes
    this->age = 0;
    this->sen = "";
    this->curr_standing = "";
}
Student::Student(string snum, string last, string mid, string first, string crs, int y, int m, int d, float g) {
// Inputed values are inserted directly to the attributes
    this->student_number = snum;
    this->lName = last;
    this->mName = mid;
    this->fName = first;
    this->course = crs;
    this->year = y;
    this->month = m;
    this->day = d;
    this->gwa = g;
// Calculated values are calculated using utility methods, then inserted to the attributes
    this->age = findAge(y, m, d);
    this->sen = findSen(snum);
    this->curr_standing = findStand(g);
}

//Getter Functions below using Encapsulation

string Student::getSnum() { return student_number; }  // Get Student Number
string Student::getName() { return lName + ", " + fName + " " + mName; }  // Get Student Name
string Student::getBday() {  // Get Birthday of Student
    string date = to_string(year) + "/" + to_string(month) + "/" + to_string(day);  // Get the date of birthday in string
    return date;
}
string Student::getCourse() { return course; } // Get Course of Student
float Student::getGWA() { return gwa; }   // Get GWA of Student
int Student::getAge() { return age; } // Get Age of Student
string Student::getSen() { return sen; } // Get Seniority of Student
string Student::getStand() { return curr_standing; } // Get Current Standing of Student

// Setter Functions below

void Student::setSnum(string snum) { student_number = snum; }    // Set Student Number
void Student::setLast(string lname) { lName = lname; }    // Set Student's Last Name
void Student::setMid(string mname) { mName = mname; }    // Set Student's Middle Name
void Student::setFirst(string fname) { fName = fname; }    // Set Student's First Name
void Student::setBday(int y, int m, int d) {   // Set Student's Birthday
    year = y;
    month = m;
    day = d;
}
void Student::setCourse(string crs) { course = crs; }   //Set Student's Course
void Student::setGWA(float GWA) { gwa = GWA; }    // Set Student's GWA
void Student::setAge(int a) { age = a; } // Set Student's Age
void Student::setSen(string s) { sen = s; }  // Set Student's Seniority
void Student::setStand(string stand) { curr_standing = stand; }  // Set Student's Standing

// Utility Methods

int Student::findAge(int y, int m, int d) {  // Method for finding the age of the Student using his/her Birthday
    time_t now = time(0);   // Starts a timer
    tm* ltm = localtime(&now);  // Stops the timer and gets the current time and date now
    int age = ((1900 + ltm->tm_year) - y) - 1;  // Gets the age by getting the date of the current year then subtracting it from the birth year -1
    //if (y < (1900 + ltm->tm_year)) return age;  // if the birth year is lesser than the current year then return age
    //else if (m > (1 + ltm->tm_mon)) return age++;   // if the 
    //else if (m == (1 + ltm->tm_mon) && d >= (ltm->tm_mday)) return age++;

    if (m == (1 + ltm->tm_mon) && d >= (ltm->tm_mday)) return age++;  // If the birth month is the same as the current month, and the birth day is greater than or equal to the current day, then increment the age
    else if (m > (1 + ltm->tm_mon)) return age++;    // if the birth month is greater than the current month then increment the age
    return age; // If it is neither then return age
}
string Student::findSen(string snum) {  // Method for finding the seniority of the Student using his/her Student Number
    time_t now = time(0);   // Starts a timer
    tm* ltm = localtime(&now);;   // Stops the timer and gets the current time and date now
    int curr_year = 1900 + ltm->tm_year;    // Get the current year
    int fresh_year = 0; // This integer stores the freshman year of the student
    snum = snum.erase(5);   // Get the freshman year of the student by isolating the first four numbers in the student number
    fresh_year = stoi(snum);    // Convert the string freshman year to integer
    //if ((1 + ltm->tm_mon) > 8) fresh_year++;    // If the current month is less than 8 or less than August, then add a year to the freshman year
    int sen = curr_year - (fresh_year + ((1 + ltm->tm_mon) < 8));

    /* To get the seniority, subtract the current year by the freshman year.
    *   Formula: Current year - (Freshman year+(Current month<8))
    *   *Since the "Current month < 8" part of the formula leads to a boolean, then if it is true increments by 1 else 0
    *   Example: Current year = 2021; Current month = Feb;  Freshman year = 2019
    *           2021-(2019+1) = 1 ; 2nd Year
    *
    *   If this month was now August then it would be like this:
    *            Current month = Aug;
    *           2021-(2019+0) = 2 ; 3rd Year
    */

    if (sen <= 0) return "1st Year";    // If the resulting value is 0, then the student is in his 1st year
    else if (sen == 1) return "2nd Year";    // If the resulting value is 1, then the student is in his 2nd year
    else if (sen == 2) return "3rd Year";    // If the resulting value is 2, then the student is in his 3rd year
    else if (sen == 3) return "4th Year";    // If the resulting value is 3, then the student is in his 4th year
    else return "Graduate";    // If the resulting value is 4 or more, then the student has supposedly graduated
}
string Student::findStand(float g) { //  Method for finding the standing of the student
    /* The following are the bounds of the grade and its corresponding standing
    *  The left number is the lower bound and the right number is the upper bound
    *  Example: [3,1.75) = Pass; [1.75,1.45) = Cum Laude; etc...
    */
    if (g <= 3 && g > 1.75) return "Pass";
    if (g <= 1.75 && g > 1.45) return "Cum Laude";
    if (g <= 1.45 && g > 1.20) return "Magna Cum Laude";
    if (g <= 1.20) return "Summa Cum Laude";
    return "Fail";  // If the GWA is greater than 3 (3.01 or more) then the student failed
}
string Student::getLastFirst() { return this->lName + this->fName; }    // Special getter method for returning the Last and First Name
string Student::getGWALast() { return to_string(this->gwa) + lName; }   // Special getter method for returning GWA and Last Name

