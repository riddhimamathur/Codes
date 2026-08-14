/*
Create a dynamic string.
Whenever the user types another word,
expand memory using realloc().
Finally print the complete sentence.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sentence = NULL;   
    char word[100];          
    int length = 0;  
    char choice;

    do {
        printf("Enter a word: ");
        scanf("%99s", word);   
        int wordLen = strlen(word);
        int newLength = length + wordLen + (length > 0 ? 1 : 0) + 1;
        char *temp = realloc(sentence, newLength);
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            free(sentence);
            return 1;
        }
        sentence = temp;
        if (length == 0) {
            strcpy(sentence, word);
        } else {
            strcat(sentence, " ");
            strcat(sentence, word);
        }
        length = strlen(sentence);
        printf("Add another word? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("\nFinal sentence: %s\n", sentence);
    free(sentence);
    return 0;
}
