#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    float price;
};

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);
    getchar(); 

    struct Book *books = (struct Book*) malloc(n * sizeof(struct Book));
    if (books == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input book details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of book %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &books[i].id);
        getchar();

        printf("Name: ");
        fgets(books[i].name, sizeof(books[i].name), stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0'; 

        printf("Price: ");
        scanf("%f", &books[i].price);
        getchar(); }
    char searchName[50];
    printf("\nEnter book name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].name, searchName) == 0) {
            printf("\nBook Found!\n");
            printf("ID: %d, Name: %s, Price: %.2f\n",
                   books[i].id, books[i].name, books[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }

    free(books);
    return 0;
}
