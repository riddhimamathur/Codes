/*
Allocate memory for a character string.
Input a sentence.
Count vowels without using array indexing ([]).*/

#include <iostream>
#include <cstdlib>   
#include <cctype>   
int main() {
    char *str = nullptr;
    char *temp = nullptr;
    int size = 0;
    int vowelCount = 0;
    char ch;

    std::cout << "Enter a sentence (press ENTER to finish):\n";

    while ((ch = getchar()) != '\n' && ch != EOF) {
        temp = (char*)realloc(str, (size + 1) * sizeof(char)); 
        if (temp == nullptr) {
            std::cout << "Memory allocation failed!\n";
            free(str);
            return 1;
        }
        str = temp;
        *(str + size) = ch;
        size++;
    }

    temp = (char*)realloc(str, (size + 1) * sizeof(char));  
    if (temp == nullptr) {
        std::cout << "Memory allocation failed!\n";
        free(str);
        return 1;
    }
    str = temp;
    *(str + size) = '\0';

  
    char *ptr = str;
    while (*ptr != '\0') {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            vowelCount++;
        }
        ptr++;
    }

    std::cout << "Sentence: " << str << "\n";
    std::cout << "Number of vowels: " << vowelCount << "\n";

    free(str);
    return 0;
}
