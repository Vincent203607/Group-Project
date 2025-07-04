#include <stdio.h>
#include <string.h>
#include "student.h"

void add_student(Student *students, int *num_students) {
    if (*num_students >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[*num_students].id);
    printf("Enter student name: ");
    getchar(); // Consume newline
    fgets(students[*num_students].name, 100, stdin);
    students[*num_students].name[strcspn(students[*num_students].name, "\n")] = '\0';  // Remove newline

    printf("Enter GPA: ");
    scanf("%f", &students[*num_students].gpa);

    printf("Enter intake year: ");
    scanf("%d", &students[*num_students].intake_year);

    printf("Enter major: ");
    getchar();  // Consume newline
    fgets(students[*num_students].major, 50, stdin);
    students[*num_students].major[strcspn(students[*num_students].major, "\n")] = '\0';  // Remove newline

    (*num_students)++;
}

void list_students(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f, Intake Year: %d, Major: %s\n",
               students[i].id, students[i].name, students[i].gpa, students[i].intake_year, students[i].major);
    }
}

void sort_students_by_gpa(Student *students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[i].gpa < students[j].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by GPA.\n");
}

void search_student_by_id(Student *students, int num_students) {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == search_id) {
            printf("Student found: ID: %d, Name: %s, GPA: %.2f, Intake Year: %d, Major: %s\n",
                   students[i].id, students[i].name, students[i].gpa, students[i].intake_year, students[i].major);
            return;
        }
    }
    printf("Student not found.\n");
}

void search_students_by_major(Student *students, int num_students) {
    char search_major[50];
    printf("Enter major to search: ");
    getchar();  // Consume newline
    fgets(search_major, 50, stdin);
    search_major[strcspn(search_major, "\n")] = '\0';  // Remove newline

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].major, search_major) == 0) {
            printf("Student found: ID: %d, Name: %s, GPA: %.2f, Intake Year: %d, Major: %s\n",
                   students[i].id, students[i].name, students[i].gpa, students[i].intake_year, students[i].major);
        }
    }
}

void update_gpa(Student *students, int num_students) {
    int search_id;
    printf("Enter student ID to update GPA: ");
    scanf("%d", &search_id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == search_id) {
            printf("Current GPA: %.2f\n", students[i].gpa);
            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);
            printf("GPA updated.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
