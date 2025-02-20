#include <stdio.h>

#define MAX_SUBJECTS 3

// Structure to hold marks for 3 subjects
struct Marks {
    int subject1;
    int subject2;
    int subject3;
};

// Structure to hold student details
struct Student {
    int ID;
    char Name[50];
    struct Marks marks;
    int total;
    float average;
    char grade;
};

// Function prototypes
void readStudents(struct Student students[], int n);
void calculateGrades(struct Student students[], int n);
void displayStudents(struct Student students[], int n);

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    readStudents(students, n);
    calculateGrades(students, n);
    displayStudents(students, n);

    return 0;
}

// Function to read student details
void readStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details (ID, Name, Marks in 3 subjects) for student %d: ", i + 1);
        scanf("%d %s %d %d %d", &students[i].ID, students[i].Name, 
              &students[i].marks.subject1, 
              &students[i].marks.subject2, 
              &students[i].marks.subject3);
    }
}

// Function to calculate total marks, average, and grade
void calculateGrades(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].total = students[i].marks.subject1 + 
                             students[i].marks.subject2 + 
                             students[i].marks.subject3;
        students[i].average = students[i].total / (float)MAX_SUBJECTS;

        // Determine grade based on average
        if (students[i].average >= 90) {
            students[i].grade = 'A';
        } else if (students[i].average >= 75) {
            students[i].grade = 'B';
        } else if (students[i].average >= 60) {
            students[i].grade = 'C';
        } else if (students[i].average >= 50) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
}

// Function to display student details
void displayStudents(struct Student students[], int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - Total: %d, Average: %.2f, Grade: %c\n", 
               students[i].Name, 
               students[i].total, 
               students[i].average, 
               students[i].grade);
    }
}
