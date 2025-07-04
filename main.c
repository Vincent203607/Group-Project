#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice;

    // Load existing students from file if it exists
    num_students = load_students(students);

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Sort Students by GPA\n");
        printf("4. Search Student by ID\n");
        printf("5. Search Students by Major\n");
        printf("6. Update GPA\n");
        printf("7. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                list_students(students, num_students);
                break;
            case 3:
                sort_students_by_gpa(students, num_students);
                break;
            case 4:
                search_student_by_id(students, num_students);
                break;
            case 5:
                search_students_by_major(students, num_students);
                break;
            case 6:
                update_gpa(students, num_students);
                break;
            case 7:
                save_students(students, num_students);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
