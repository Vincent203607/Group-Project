#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[100];
    float gpa;
    int intake_year;
    char major[50];
} Student;

void add_student(Student *students, int *num_students);
void list_students(Student *students, int num_students);
void sort_students_by_gpa(Student *students, int num_students);
void search_student_by_id(Student *students, int num_students);
void search_students_by_major(Student *students, int num_students);
void update_gpa(Student *students, int num_students);

#endif
