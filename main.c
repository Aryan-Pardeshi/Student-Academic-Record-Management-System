#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define COURSE_LEN 30
#define THESIS_LEN 100

enum StudentType {
    UG,
    PG
};

union StudentData {
    struct {
        int semester;
        float cgpa;
    } ug;
    struct {
        char thesisTitle[THESIS_LEN];
        float researchScore;
    } pg;
};

struct Student {
    int studentID;
    char name[NAME_LEN];
    int age;
    char course[COURSE_LEN];
    enum StudentType type;
    union StudentData data;
};

struct Student records[MAX_STUDENTS];
int numStudents = 0;

int findStudent(int id) {
    for (int i = 0; i < numStudents; i++) {
        if (records[i].studentID == id) {
            return i;
        }
    }
    return -1;
}

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    struct Student newStudent;
    int typeChoice;

    printf("Enter Student ID: ");
    scanf("%d", &newStudent.studentID);

    if (findStudent(newStudent.studentID) != -1) {
        printf("Student with this ID already exists.\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Course: ");
    scanf(" %[^\n]", newStudent.course);

    printf("Enter Student Type (1 for UG, 2 for PG): ");
    scanf("%d", &typeChoice);

    if (typeChoice == 1) {
        newStudent.type = UG;
        printf("Enter Semester: ");
        scanf("%d", &newStudent.data.ug.semester);
        printf("Enter CGPA: ");
        scanf("%f", &newStudent.data.ug.cgpa);
    } else if (typeChoice == 2) {
        newStudent.type = PG;
        printf("Enter Thesis Title: ");
        scanf(" %[^\n]", newStudent.data.pg.thesisTitle);
        printf("Enter Research Score: ");
        scanf("%f", &newStudent.data.pg.researchScore);
    } else {
        printf("Invalid student type.\n");
        return;
    }

    records[numStudents] = newStudent;
    numStudents++;
    printf("Student added successfully.\n");
}

void displayStudent(int index) {
    printf("------------------------------------\n");
    printf("Student ID: %d\n", records[index].studentID);
    printf("Name: %s\n", records[index].name);
    printf("Age: %d\n", records[index].age);
    printf("Course: %s\n", records[index].course);

    if (records[index].type == UG) {
        printf("Type: Undergraduate\n");
        printf("Semester: %d\n", records[index].data.ug.semester);
        printf("CGPA: %.2f\n", records[index].data.ug.cgpa);
    } else {
        printf("Type: Postgraduate\n");
        printf("Thesis Title: %s\n", records[index].data.pg.thesisTitle);
        printf("Research Score: %.2f\n", records[index].data.pg.researchScore);
    }
    printf("------------------------------------\n");
}

void displayStudents() {
    if (numStudents == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- All Student Records ---\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudent(i);
    }
}

void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
    } else {
        printf("Student found:\n");
        displayStudent(index);
    }
}

void updateStudent() {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", records[index].name);
    printf("Enter new Age: ");
    scanf("%d", &records[index].age);
    printf("Enter new Course: ");
    scanf(" %[^\n]", records[index].course);

    int typeChoice;
    printf("Enter new Student Type (1 for UG, 2 for PG): ");
    scanf("%d", &typeChoice);

    if (typeChoice == 1) {
        records[index].type = UG;
        printf("Enter new Semester: ");
        scanf("%d", &records[index].data.ug.semester);
        printf("Enter new CGPA: ");
        scanf("%f", &records[index].data.ug.cgpa);
    } else if (typeChoice == 2) {
        records[index].type = PG;
        printf("Enter new Thesis Title: ");
        scanf(" %[^\n]", records[index].data.pg.thesisTitle);
        printf("Enter new Research Score: ");
        scanf("%f", &records[index].data.pg.researchScore);
    } else {
        printf("Invalid student type. Update aborted.\n");
        return;
    }

    printf("Student record updated successfully.\n");
}

void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    int index = findStudent(id);

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < numStudents - 1; i++) {
        records[i] = records[i + 1];
    }

    numStudents--;
    printf("Student record deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Academic Record Management\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
