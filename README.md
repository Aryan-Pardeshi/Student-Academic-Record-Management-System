# Student Academic Record Management System

A simple, menu-driven C program to manage student academic records using structures and unions. This project demonstrates the use of core C data structures to handle related but varied data types efficiently.

## 🏛️ Project Description

This program is designed to manage academic records for a university. It can store common details for all students and also accommodate specific data for two different student types: **Undergraduate (UG)** and **Postgraduate (PG)**.

-----

## ✨ Features

The program provides a simple command-line interface with the following functionalities:

  * **Add Student:** Input common details and type-specific details for a new student.
  * **Display All Students:** List all student records currently stored.
  * **Search Student by ID:** Find and display a specific student's record using their unique ID.
  * **Update Student Record:** Modify the details of an existing student.
  * **Delete Student Record:** Remove a student's record from the system.

-----

## 🛠️ Core Concepts & Requirements

This program was built using the following C concepts as per the requirements:

  * **`struct`:** A main `Student` structure is used to bundle the common data (ID, Name, Age, Course) and the type-specific data.
  * **`enum`:** An `enum` (`StudentType { UG, PG }`) is used as a tag to identify which type of student is being stored.
  * **`union`:** A `union` (`StudentData`) is nested inside the main `struct` to store the type-specific data. This ensures memory efficiency, as only the data for *either* a UG *or* a PG student is stored, not both.
  * **Array of Structures:** A global array (`records[MAX_STUDENTS]`) is used to store all the student records.
  * **Menu-Driven Interface:** A `while` loop and `switch` statement are used to create a simple and interactive user menu.

-----

## 💾 Data Structure Design

The core of the program is its data structure:

1.  **Common Details** (Stored for every student):

      * `studentID` (integer)
      * `name` (string)
      * `age` (integer)
      * `course` (string)

2.  **Type-Specific Details** (Stored in a `union`):

      * **If Undergraduate:**
          * `semester` (integer)
          * `cgpa` (float)
      * **If Postgraduate:**
          * `thesisTitle` (string)
          * `researchScore` (float)

-----

## 🚀 Sample Usage

Here is a sample interaction with the running program:

```text
Student Academic Record Management
1. Add Student
2. Display All Students
3. Search Student by ID
4. Update Student Record
5. Delete Student Record
0. Exit
Enter your choice: 1
Enter Student ID: 101
Enter Name: Rohan Sharma
Enter Age: 19
Enter Course: Computer Engineering
Enter Student Type (1 for UG, 2 for PG): 1
Enter Semester: 3
Enter CGPA: 8.75
Student added successfully.

Student Academic Record Management
1. Add Student
2. Display All Students
3. Search Student by ID
4. Update Student Record
5. Delete Student Record
0. Exit
Enter your choice: 1
Enter Student ID: 201
Enter Name: Priya Singh
Enter Age: 23
Enter Course: Data Science
Enter Student Type (1 for UG, 2 for PG): 2
Enter Thesis Title: AI in Healthcare
Enter Research Score: 9.2
Student added successfully.

Student Academic Record Management
1. Add Student
2. Display All Students
3. Search Student by ID
4. Update Student Record
5. Delete Student Record
0. Exit
Enter your choice: 2

--- All Student Records ---
------------------------------------
Student ID: 101
Name: Rohan Sharma
Age: 19
Course: Computer Engineering
Type: Undergraduate
Semester: 3
CGPA: 8.75
------------------------------------
------------------------------------
Student ID: 201
Name: Priya Singh
Age: 23
Course: Data Science
Type: Postgraduate
Thesis Title: AI in Healthcare
Research Score: 9.20
------------------------------------

Student Academic Record Management
1. Add Student
2. Display All Students
3. Search Student by ID
4. Update Student Record
5. Delete Student Record
0. Exit
Enter your choice: 0
Exiting program.
```
