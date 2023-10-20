#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct Student {
    char name[50];
    char roll_number[20];
    float cgpa;
};

// Comparison function for qsort to sort students by CGPA in descending order
int compare_students(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    return (studentB->cgpa > studentA->cgpa) - (studentB->cgpa < studentA->cgpa);
}

// Function to sort students based on CGPA in descending order
void sort_students(struct Student *students, int num_students) {
    qsort(students, num_students, sizeof(struct Student), compare_students);
}

// Function to print a list of students
void print_students(struct Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Roll Number: %s, CGPA: %.2f\n",
            students[i].name, students[i].roll_number, students[i].cgpa);
    }
}

int main() {
    struct Student students[] = {
        {"Alice", "A001", 3.8},
        {"Bob", "B002", 3.5},
        {"Charlie", "C003", 3.9},
        {"David", "D004", 3.7}
    };
    int num_students = sizeof(students) / sizeof(students[0]);

    printf("Unsorted Students:\n");
    print_students(students, num_students);

    sort_students(students, num_students);

    printf("\nStudents Sorted by CGPA (Descending):\n");
    print_students(students, num_students);

    return 0;
}
