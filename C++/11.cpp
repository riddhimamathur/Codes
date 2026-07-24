/*create a structure

struct Student
{
    int roll;
    char name[30];
    float marks;
};

Allocate memory for N students dynamically.*/
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[30];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

   
    struct Student *students = (struct Student*) malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Marks: %d\n",
               students[i].roll, students[i].name, students[i].marks);
    }
    free(students);

    return 0;
}
