/*longest word from the paragraph*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* para = (char*) malloc (1000 * sizeof(char));
    printf("enter the paragrapgh : \n");
    fgets (para,1000,stdin);

    char* word = strtok(para, " , .-\n");
    char longest[100]= " ";
    while(word!=NULL)
    {
        if (strlen(word)>strlen(longest))
     strcpy(longest , word);
     word = strtok (NULL , " ,.-\n");}
     printf("longest word : %s", longest);
     free(para);
     return 0;    
}