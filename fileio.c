#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int load_students(Student *students) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        return 0;
    }

    int num_students = 0;
    while (fscanf(file, "%d,%99[^,],%f,%d,%49[^\n]\n",
                   &students[num_students].id, students[num_students].name,
                   &students[num_students].gpa, &students[num_students].intake_year,
                   students[num_students].major) == 5) {
        num_students++;
    }

    fclose(file);
    return num_students;
}

void save_students(Student *students, int num_students) {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error saving to file.\n");
        return;
    }

    for (int i = 0; i < num_students; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%s\n", students[i].id, students[i].name, students[i].gpa, students[i].intake_year, students[i].major);
    }

    fclose(file);
}
