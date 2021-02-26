#pragma once
// Created by Andrew Louis Robledo Hermo -- February 16, 2021 -- University of the Philippines Mindano -- BS Computer Science
#include <string>
#include <chrono>

using namespace std;

class Student{  // Class that stores the student info
    private:
        string student_number; 
        string lName;
        string mName;
        string fName;
        string course;
        int year;
        int month;
        int day;
        float gwa;
        int age;
        string sen;
        string curr_standing;

    public:
        // Constructor
        Student();
        Student(string snum, string last, string mid, string first, string crs, int y, int m, int d, float g);

        //Getter Functions below using Encapsulation

        string getSnum();// Get Student Number
        string getName();// Get Student Name
        string getBday();// Get Birthday of Student
        string getCourse();// Get Course of Student
        float getGWA();// Get GWA of Student
        int getAge();// Get Age of Student
        string getSen();// Get Seniority of Student
        string getStand();// Get Current Standing of Student

        // Setter Functions below

        void setSnum(string snum);// Set Student Number
        void setLast(string lname);// Set Student's Last Name
        void setMid(string mname);// Set Student's Middle Name
        void setFirst(string fname);// Set Student's First Name
        void setBday(int y, int m, int d);// Set Student's Birthday
        void setCourse(string crs); // Set Student's Course
        void setGWA(float GWA);// Set Student's GWA
        void setAge(int a);// Set Student's Age
        void setSen(string s);// Set Student's Seniority
        void setStand(string stand);// Set Student's Standing

        // Utility Methods

        int findAge(int y, int m, int d); // Method for finding the age of the Student using his/her Birthday
        string findSen(string snum); // Method for finding the seniority of the Student using his/her Student Number
        string findStand(float g);//  Method for finding the standing of the student
        string getLastFirst(); // Special getter method for Last and First Name
        string getGWALast(); // Special getter method for GWA and Last Name
};

