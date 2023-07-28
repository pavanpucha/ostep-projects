#include<stdio.h>
#include<string.h>
#define SIZE 2048

int main(int argc, char *argv[]){
    void minigrep(FILE *fp, char* parsee);

    FILE *fp ;
    char *prog = argv[0]; /* program name for the errors*/

    if(argc == 1) {
        return 0;
    }
    else {
        char gret_arg = argv[1];
        
    while (-- argc > 0){
        if((fp = fopen(*++argv, "r")) == NULL){
        printf("wgrep: cannot open file\n");
        return 1;
        } else {
            minigrep(fp, argv[1]);
            fclose(fp);
        }
    }
    }

    if(ferror(stdout)){
        fprintf(stderr, "%s error writing to stdout \n", prog);
      return 1;
    }
    return 0;
}


void minigrep(FILE *input, char* parsee){
    char read_line[SIZE];
    while(fgets(read_line, SIZE, input) != NULL){
        if(strstr(read_line,parsee))
        printf("%s", read_line);
    }
}