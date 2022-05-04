#include<stdio.h>

int main(int argc, char* argv[])
{
    int *p = new int(2);

    printf("hello%08x.%08x.%08x.%08x.%n", 2, 2, 2, 2, p);
    printf("%d", *p);

    return 0;
}