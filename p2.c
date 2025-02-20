#include <stdio.h>

struct Employee_t {
    int id;
    char name[10];
    float salary;
    char department[10];
};

typedef struct Employee_t Employee;

void readEmployee(Employee emp[], int n);
void displayEmployee(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);
void saveEmployee(Employee emp[], int n);
void loadEmployee(Employee emp[], int *n);

int main() {
    int employeeCount;
    printf("Enter number of employees: ");
    scanf("%d", &employeeCount);
    
    if (employeeCount > 10) {
        printf("Maximum number of employees is 10.\n");
        return 1;
    }

    Employee employee[10];
    readEmployee(employee, employeeCount);
    displayEmployee(employee, employeeCount);
    
    Employee highestSalaryEmployee = findHighestSalary(employee, employeeCount);
    printf("Employee with highest salary: %d, %s, %.2f (%s)\n", 
           highestSalaryEmployee.id, highestSalaryEmployee.name, 
           highestSalaryEmployee.salary, highestSalaryEmployee.department);
    

    saveEmployee(employee, employeeCount);
    
    
    Employee loadedEmployees[10];
    int loadedCount = 0;
    loadEmployee(loadedEmployees, &loadedCount);
    
    printf("Loaded Employees:\n");
    displayEmployee(loadedEmployees, loadedCount);
    
    return 0;
}

void readEmployee(Employee emp[], int n) {
    printf("Enter employee details (ID, Name, Salary, Department):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %s %f %s", &emp[i].id, emp[i].name, &emp[i].salary, emp[i].department);
    }
}

void saveEmployee(Employee emp[], int n) {
    FILE *file = fopen("employee.txt", "w");
    if (file == NULL) {
        printf("Cannot create file\n");
        return;
    }
    for (int i = 0; i < n; i++) { 
        fprintf(file, "%d %s %.2f %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
    fclose(file); 
}

void loadEmployee(Employee emp[], int *n) {
    FILE *file = fopen("employee.txt", "r"); 
    if (file == NULL) {
        printf("Cannot open file\n");
        *n = 0; 
        return;
    }
    *n = 0; 
    while (fscanf(file, "%d %s %f %s", &emp[*n].id, emp[*n].name, &emp[*n].salary, emp[*n].department) == 4) {
        (*n)++;
        if (*n >= 10) break; 
    }
    fclose(file);
}

void displayEmployee(Employee emp[], int n) {
    printf("Employees:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s - %.2f - %s\n", emp[i].id, emp[i].name, emp[i].salary, emp[i].department);
    }
}

Employee findHighestSalary(Employee emp[], int n) {
    Employee highestSalary = emp[0];
    for (int i = 1; i < n; i++) {
        if (emp[i].salary > highestSalary.salary) {
            highestSalary = emp[i];
        }
    }
    return highestSalary; 
}
