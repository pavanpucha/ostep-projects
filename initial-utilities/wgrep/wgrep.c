#include <stdio.h>
#include <string.h>
#define SIZE 2048

int main(int argc, char *argv[])
{
    void minigrep(FILE * fp, char *parsee);

    FILE *fp;
    char *prog = argv[0]; /* program name for the errors*/

    if (argc == 1) // No searchterm passed
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    else if (argc == 2) // Only search term is passed as an argument, means we read from stdin
    {
        char *grep_arg = argv[1];
        argv++;
        --argc;
        minigrep(stdin, grep_arg);
    }
    else
    {
        char *grep_arg = argv[1];
        argv++;
        --argc;
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("wgrep: cannot open file\n");
                return 1;
            }
            else
            {
                minigrep(fp, grep_arg);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout))
    {
        fprintf(stderr, "%s error writing to stdout \n", prog);
        return 1;
    }
    return 0;
}

void minigrep(FILE *input, char *grep_arg)
{
    char read_line[SIZE];
    while (fgets(read_line, SIZE, input) != NULL)
    {
        if (strstr(read_line, grep_arg))
            printf("%s", read_line);
    }
}