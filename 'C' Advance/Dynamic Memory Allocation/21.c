#include <stdio.h>
#include <stdlib.h>

char* my_strcpy(const char* src) {
    int len = 0;
    while (src[len] != '\0') {
        len++;
    }

    char* dest = (char*)malloc((len + 1) * sizeof(char));
    if (dest == NULL) return NULL;

    for (int i = 0; i <= len; i++) {
        dest[i] = src[i];
    }

    return dest;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    char* copy = my_strcpy(str);
    if (copy != NULL) {
        printf("Copied string: %s\n", copy);
        free(copy);
    }

    return 0;
}
