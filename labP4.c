#include <stdio.h>
#include <stdlib.h>

void appendStudentRecord();
void displayStudentRecords();

int main() {
    int choice;

    do {
        printf("1. Append Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                appendStudentRecord();
                break;
            case 2:
                displayStudentRecords();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void appendStudentRecord() {
    FILE *file;
    int id;
    char name[50];
    int score1, score2, score3;

    // Open the file in append mode
    file = fopen("students.txt", "a");
    if (file == NULL) {
        printf("Could not open file for appending.\n");
        return;
    }

    // Get student details from the user
    printf("Enter student ID, Name, Score1, Score2, Score3 (comma-separated): ");
    scanf("%d, %49[^,], %d, %d, %d", &id, name, &score1, &score2, &score3);

    // Write the student record to the file
    fprintf(file, "%d %s %d %d %d\n", id, name, score1, score2, score3);

    // Close the file
    fclose(file);
    printf("Student record appended successfully.\n");
}

void displayStudentRecords() {
    FILE *file;
    char line[256];

    // Open the file in read mode
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Could not open file for reading.\n");
        return;
    }

    printf("Student Records:\n");
    // Read and display each line from the file
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    
    fclose(file);
}
