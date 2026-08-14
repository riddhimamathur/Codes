/*Store employee records dynamically.
Sort them according to salary.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void sortBySalary(Employee *arr, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
         {
            if (arr[i].salary > arr[j].salary) 
            {
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(Employee *arr, int n) {
    printf("\nSorted Employee Records (by Salary):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", arr[i].id, arr[i].name, arr[i].salary);
    }
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    Employee *arr = (Employee*) malloc(n * sizeof(Employee));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &arr[i].id);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Salary: ");
        scanf("%f", &arr[i].salary);
    }
    sortBySalary(arr, n);
    display(arr, n);
    free(arr);

    return 0;
}
