/*
    The C programming Language, 2nd ed.  Section 7.5
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void filecopy(FILE *, FILE *);
    void fileerr(char *);

    FILE *fp ;

    if(argc == 1)
        filecopy(stdin, stdout);
    else 
    while (-- argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL){
            fileerr(*argv);
        } else {
            filecopy(fp, stdout);
            fclose(fp);
        }
    }
    return 0;
}

// Method to print the file
void fileerr(char *filename){
        printf("wcat: cannot open file %s \n", *filename);
        exit(1);
}

void filecopy(FILE *input, FILE *output){
    int c; 
    while(( c= getc(input)) != EOF)
        putc(c, output);
}

