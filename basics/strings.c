#include<stdio.h>
#include<string.h>

void printStr(char str[]){
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    
}



int main()
{
    // char name[20] = "shantanu";
    // printf("%s", name[15]);

    // char name[20];
    // gets(name);
    // puts(name);

    // char str[] = "happy";
    // printStr(str);

    // char str1[] = "Happy", str2[] = "Beniwal";
    // printf("%s", strcat(str1, str2));
    // printf("%d", strlen(str1));
    // printf("%s", strrev(str1));

    // char str3[10];
    // strcpy(str3, str1);
    // printf("%s", str3);

    return 0;

}