/*
    The C programming Language, 2nd ed.  Section 7.5, 7.6
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void filecopy(FILE *, FILE *);

    FILE *fp ;
    char *prog = argv[0]; /* program name for the errors*/

    if(argc == 1) {
        return 0;
    }
    else 
    while (-- argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL){
        printf("wcat: cannot open file\n");
        return 1;
        } else {
            filecopy(fp, stdout);
            fclose(fp);
        }
    }

    if(ferror(stdout)){
        fprintf(stderr, "%s error writing to stdout \n", prog);
      return 1;
    }
    return 0;
}

void filecopy(FILE *input, FILE *output){
    int c; 
    while(( c= getc(input)) != EOF)
        putc(c, output);
}