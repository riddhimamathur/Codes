/* 
QUES 7.
Read marks of students.
After every student,
ask whether another student should be added.
Use realloc() after each addition.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *marks = NULL;  
    int count = 0;    
    int choice;

    do {
        printf("\nchoose any one from the below :\n");
        printf("1. Add student\n");
        printf("2. Stop and display marks\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            count++;
            marks = (int*) realloc(marks, count * sizeof(int));
            if (marks == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }
            printf("Enter marks of student %d: ", count);
            scanf("%d", &marks[count - 1]);
        }

    } while (choice != 2);    
    printf("\nMarks of students:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
    free(marks);

    return 0;
}
