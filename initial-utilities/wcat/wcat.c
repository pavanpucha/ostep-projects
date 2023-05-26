/*
    The C programming Language, 2nd ed.  Section 7.5
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void filecopy(FILE *, FILE *);
  
    FILE *fp = fopen("wcat.c", "r");
    if (fp == NULL)
    {
        printf("wcat: cannot open file \n");
        exit(1);
    }
    else
    {
        filecopy(fp, stdout);
    }
    return 0;
}


// Method to print the file

void filecopy(FILE *input, FILE *output){
    int c; 
    while(( c= getc(input)) != EOF)
        putc(c, output);

}

