#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of students we can store
#define MAX_STUDENTS 50

// Structure representing a student
struct Student {
    char name[50];
    char surname[50];
    int age;
};

void displayMenu() {
    printf("\nMenu:\n");
    printf("1) Add a student\n");
    printf("2) Delete a student\n");
    printf("3) List all students\n");
    printf("0) Exit\n");
    printf("Your choice -> ");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numStudents < MAX_STUDENTS) {
                    printf("Enter name -> ");
                    scanf("%s", students[numStudents].name);

                    printf("Enter surname -> ");
                    scanf("%s", students[numStudents].surname);

                    printf("Enter age -> ");
                    scanf("%d", &students[numStudents].age);

                    numStudents++;

                    printf("Student added!\n");
                } else {
                    printf("You've reached the maximum number of students (%d).\n", MAX_STUDENTS);
                }
                break;
            case 2:
                if (numStudents > 0) {
                    int studentIndex;
                    printf("Enter the index of the student you want to delete (0-%d) -> ", numStudents - 1);
                    scanf("%d", &studentIndex);

                    if (studentIndex >= 0 && studentIndex < numStudents) {
                        // Move the student to be deleted to the last position and decrease the number of students
                        strcpy(students[studentIndex].name, students[numStudents - 1].name);
                        strcpy(students[studentIndex].surname, students[numStudents - 1].surname);
                        students[studentIndex].age = students[numStudents - 1].age;
                        numStudents--;

                        printf("Student deleted!\n");
                    } else {
                        printf("Invalid student index.\n");
                    }
                } else {
                    printf("The list of students is empty.\n");
                }
                break;
            case 3:
                if (numStudents > 0) {
                    printf("\nList of all students:\n");
                    for (int i = 0; i < numStudents; i++) {
                        printf("Student %d:\n", i + 1);
                        printf("Name: %s\n", students[i].name);
                        printf("Surname: %s\n", students[i].surname);
                        printf("Age: %d\n", students[i].age);
                    }
                } else {
                    printf("The list of students is empty.\n");
                }
                break;
            case 0:
                printf("Thank you for using the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

