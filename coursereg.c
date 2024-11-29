#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 50

typedef struct {
    int id;
    char name[50];
    int enrolledCourses[10];
    int courseCount;
} Student;

typedef struct {
    int id;
    char name[50];
    char schedule[20];
    int enrolledStudents[100];
    int studentCount;
} Course;

// Global arrays
Student students[MAX_STUDENTS];
Course courses[MAX_COURSES];
int studentCount = 0;
int courseCount = 0;

// Function declarations
void addStudent();
void addCourse();
void enrollStudent();
void viewStudents();
void viewCourses();

int main() {
    int choice;

    while (1) {
        printf("\n--- Course Registration System ---\n");
        printf("1. Add Student\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student in a Course\n");
        printf("4. View Students\n");
        printf("5. View Courses\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addCourse(); break;
            case 3: enrollStudent(); break;
            case 4: viewStudents(); break;
            case 5: viewCourses(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function definitions
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", students[studentCount].name);

    students[studentCount].courseCount = 0;
    studentCount++;

    printf("Student added successfully!\n");
}

void addCourse() {
    if (courseCount >= MAX_COURSES) {
        printf("Maximum course limit reached!\n");
        return;
    }

    printf("Enter course ID: ");
    scanf("%d", &courses[courseCount].id);
    printf("Enter course name: ");
    scanf(" %[^\n]s", courses[courseCount].name);
    printf("Enter course schedule (e.g., Mon 10:00 AM): ");
    scanf(" %[^\n]s", courses[courseCount].schedule);

    courses[courseCount].studentCount = 0;
    courseCount++;

    printf("Course added successfully!\n");
}

void enrollStudent() {
    int studentID, courseID, i, j;

    printf("Enter student ID: ");
    scanf("%d", &studentID);
    printf("Enter course ID: ");
    scanf("%d", &courseID);

    for (i = 0; i < studentCount; i++) {
        if (students[i].id == studentID) {
            for (j = 0; j < courseCount; j++) {
                if (courses[j].id == courseID) {
                    students[i].enrolledCourses[students[i].courseCount++] = courseID;
                    courses[j].enrolledStudents[courses[j].studentCount++] = studentID;

                    printf("Student enrolled in course successfully!\n");
                    return;
                }
            }
            printf("Course not found!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void viewStudents() {
    printf("\n--- Students ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
    }
}

void viewCourses() {
    printf("\n--- Courses ---\n");
    for (int i = 0; i < courseCount; i++) {
        printf("ID: %d, Name: %s, Schedule: %s\n", courses[i].id, courses[i].name, courses[i].schedule);
    }
}
