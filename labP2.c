#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

// Structure to hold employee details
struct Employee {
    int ID;
    char Name[50];
    float Salary;
};

// Function prototypes
void writeToFile(struct Employee emp[], int n);
void readFromFile();

int main() {
    int n;
    struct Employee emp[MAX_EMPLOYEES];

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Read employee details
    printf("Enter details (ID, Name, Salary):\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d: ", i + 1);
        scanf("%d %s %f", &emp[i].ID, emp[i].Name, &emp[i].Salary);
    }

    // Write employee details to file
    writeToFile(emp, n);

    // Read and display employee details from file
    readFromFile();

    return 0;
}

// Function to write employee details to a file
void writeToFile(struct Employee emp[], int n) {
    FILE *file = fopen("employees.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %s %.2f\n", emp[i].ID, emp[i].Name, emp[i].Salary);
    }

    fclose(file);
}

// Function to read employee details from a file
void readFromFile() {
    FILE *file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    printf("\nEmployees Data from File:\n");
    struct Employee emp;
    while (fscanf(file, "%d %s %f", &emp.ID, emp.Name, &emp.Salary) != EOF) {
        printf("%d %s %.2f\n", emp.ID, emp.Name, emp.Salary);
    }

    fclose(file);
}
