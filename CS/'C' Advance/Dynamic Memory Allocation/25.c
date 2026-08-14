#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *start, char *end) 
{
    while (start < end) 
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() 
{
    char *sen = (char*)malloc(200 * sizeof(char)); // here sen stands for sentence
    if (sen == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a sentence: ");
    fgets(sen, 200, stdin);

    int len = strlen(sen);
    if (sen[len - 1] == '\n') sen[len - 1] = '\0'; 
    char *start = sen;
    char *ptr = sen;

    while (*ptr != '\0') {
        if (*ptr == ' ') {
            reverse(start, ptr - 1); 
            start = ptr + 1;                 }
        ptr++;
    }
    reverse(start, ptr - 1); 

    printf("Reversed words: %s\n", sen);

    free(sen);
    return 0;
}
