#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

struct Student {
	char name[16];
	double avg_grade;
};

int main() {
    FILE *f1 = fopen("students.bin", "rb");
    
    if (!f1) {
        perror("Error opening file");
        return 1;
    }

    struct Student students[MAX_STUDENTS];

    fread(students, sizeof(struct Student), MAX_STUDENTS, f1);

    double max_avg_grade = -1.0;
    int max_avg_grade_index = -1;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].avg_grade > max_avg_grade) {
            max_avg_grade = students[i].avg_grade;
            max_avg_grade_index = i;
        }
    }

    if (max_avg_grade_index != -1) {
        printf("Student with highest avg_grade:\n");
        printf("Name: %s\n", students[max_avg_grade_index].name);
        printf("Avg Grade: %.2lf\n", students[max_avg_grade_index].avg_grade);
    } else {
        printf("No student data found.\n");
    }

    fclose(f1);
    return 0;
}

