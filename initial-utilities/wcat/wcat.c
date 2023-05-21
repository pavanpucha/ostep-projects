/*
    The C programming Language, 2nd ed.  Section 7.5
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char str[1000];
    FILE *fp = fopen("wcat.c", "r");
    if (fp == NULL)
    {
        printf("wcat: cannot open file \n");
        exit(1);
    }
    else
    {
        while (fgets(str, 1000, fp))
        {
            printf("%s", str);
        }
    }
    return 0;
}
