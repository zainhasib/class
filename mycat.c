#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *arg1;
char *arg2;
char *arg3;
char *arg4;
const char * FILE_DOESNT_EXIST = "File doesn't exist!\n";

int getArrow(char *symbol)
{
    if (strcmp(symbol, "<") == 0)
    {
        return 1;
    }
    else if (strcmp(symbol, ">") == 0)
    {
        return 2;
    }
    else if (strcmp(symbol, ">>") == 0)
    {
        return 3;
    }
    else 
    {
        return 0;
    }
}

int main(int count, char **args)
{

    if (count == 2) // ./mycat > or ./mycat a.txt
    {
        char *arg = args[1];
        char cmd[20] = "cat < ";
        int symbol = getArrow(args[1]);
        if (symbol)
        {
            printf("You have too few arguments(just the symbols)\n");
        }
        else
        {
            FILE *file;
            file = fopen(arg, "r");
            if(file) {
                char ch[200];
                while(fscanf(file, "%s", ch) != EOF)
                    printf("%s ", ch);

                printf("\n");
                fclose(file);
            }else {
                printf("%s", FILE_DOESNT_EXIST);
            }
        }
    }
    else if (count == 3)
    {
        if(getArrow(args[1])){
            int symbol = getArrow(args[1]);
            if (getArrow(args[2]))
            {
                printf("Invalid Syntax (Double Symbols)\n");
            }
            else
            {
                char *fileName = args[2];
                if (symbol == 1)
                {
                    FILE *file;
                    file = fopen(fileName, "r");
                    if(file) {
                        char ch[200];
                        fscanf(file, "%s", ch);
                        printf("%s\n", ch);
                        fclose(file);
                    }else {
                        printf("%s", FILE_DOESNT_EXIST);
                    }
                }else if(symbol == 2) {
                    FILE *file;
                    file = fopen(fileName, "w");
                    if(file) {
                        char ch[500];
                        fgets(ch, 500, stdin);
                        fprintf(file, "%s", ch);
                        fclose(file);
                    }else {
                        printf("%s", FILE_DOESNT_EXIST);
                    }
                }else if(symbol == 3) {
                    FILE *file;
                    file = fopen(fileName, "a+");
                    if(file) {
                        char ch[500];
                        fgets(ch, 500, stdin);
                        fprintf(file, "%s", ch);
                        fclose(file);
                    }else {
                        printf("%s", FILE_DOESNT_EXIST);
                    }
                }
            }
        }else if(getArrow(args[2])){
            printf("You have arrow in the wrong position\n");
        }else {

        }
    }
    else if (count == 4)
    {
        if(getArrow(args[1])){
            int symbol = getArrow(args[1]);
            if(symbol == 1) {
                char * fileName = args[3];
                FILE *file;
                file = fopen(fileName, "r");
                if(file) {
                    char ch[200];
                    while(fscanf(file, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    printf("\n");
                    fclose(file);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 2){
                char * file1 = args[2];
                char * file2 = args[3];
                FILE * fp1 = fopen(file1, "r+");
                FILE * fp2 = fopen(file2, "w");
                if(fp1 && fp2) {
                    char ch[200];
                    ftruncate(fileno(fp2), 0);
                    fprintf(fp2, " ");
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp2, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 3) {
                char * file1 = args[2];
                char * file2 = args[3];
                FILE * fp1 = fopen(file1, "r+");
                FILE * fp2 = fopen(file2, "a+");
                if(fp1 && fp2) {
                    char ch[200];
                    ftruncate(fileno(fp2), 0);
                    fprintf(fp2, " ");
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp2, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }
        }else {
            if(getArrow(args[2])) {
                int symbol = getArrow(args[2]);
                if(symbol == 1){
                    char * file1 = args[2];
                    char * file2 = args[3];
                    FILE * fp1 = fopen(file1, "w+");
                    FILE * fp2 = fopen(file2, "r");
                    if(fp1 && fp2) {
                        char ch[200];
                        while(fscanf(fp2, "%s", ch) != EOF){
                            fprintf(fp1, "%s ", ch);
                        }
                        fclose(fp1);
                        fclose(fp2);
                    }else {
                        printf("%s", FILE_DOESNT_EXIST);
                    }
                }else if(symbol == 2) {
                    char * file1 = args[2];
                    char * file2 = args[3];
                    FILE * fp1 = fopen(file1, "w+");
                    FILE * fp2 = fopen(file2, "r");
                    if(fp1 && fp2) {
                        char ch[200];
                        while(fscanf(fp2, "%s", ch) != EOF){
                            fprintf(fp1, "%s ", ch);
                        }
                        fclose(fp1);
                        fclose(fp2);
                    }else {
                        printf("%s", FILE_DOESNT_EXIST);
                    }
                }
            }else if(getArrow(args[3])){
                printf("Symbol at the wrong position\n");
            }else {
                char * file1 = args[1];
                char * file2 = args[2];
                char * file3 = args[3];
                FILE * fp1;
                fp1 = fopen(file1, "r+");
                FILE * fp2;
                fp2 = fopen(file2, "r+");
                FILE * fp3;
                fp3 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2 && fp3) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    while(fscanf(fp3, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    printf("\n");
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }
        }
    }
    else if (count == 5)
    {
        if(getArrow(args[1])){
            int symbol = getArrow(args[1]);
            if(symbol == 1) {
                char * file2 = args[3];
                char * file3 = args[4];
                FILE * fp1 = fopen(file2, "r+");
                FILE * fp2 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    printf("\n");
                    fclose(fp1);
                    fclose(fp2);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 2) {
                char * file1 = args[2];
                char * file2 = args[3];
                char * file3 = args[4];
                FILE * fp0 = fopen(file1, "w+");
                FILE * fp1 = fopen(file2, "r+");
                FILE * fp2 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp0, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp0, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 3) {
                char * file1 = args[2];
                char * file2 = args[3];
                char * file3 = args[4];
                FILE * fp0;
                fp0 = fopen(file1, "a+");
                FILE * fp1;
                fp1 = fopen(file2, "r+");
                FILE * fp2;
                fp2 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp0, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp0, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }
        }else if(getArrow(args[2])){
            int symbol = getArrow(args[2]);
            if(symbol == 1) {
                char * file = args[3];
                char ch[200];
                FILE * fp;
                fp = fopen(file, "r");
                if(fp) {
                    while(fscanf(fp, "%s", ch) !=  EOF){
                        printf("%s", ch);
                    }
                    printf("\n");
                    fclose(fp);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 2){
                char * file1 = args[1];
                char * file2 = args[3];
                char * file3 = args[4];
                FILE * fp0;
                fp0 = fopen(file1, "r+");
                FILE * fp1;
                fp1 = fopen(file2, "w+");
                FILE * fp2;
                fp2 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2 && fp0) {
                    while(fscanf(fp0, "%s", ch) != EOF){
                        fprintf(fp1, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp1, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp0);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 3){
                char * file1 = args[1];
                char * file2 = args[3];
                char * file3 = args[4];
                FILE * fp0;
                fp0 = fopen(file1, "r+");
                FILE * fp1;
                fp1 = fopen(file2, "a+");
                FILE * fp2;
                fp2 = fopen(file3, "r+");
                char ch[300];
                if(fp1 && fp2 && fp0) {
                    while(fscanf(fp0, "%s", ch) != EOF){
                        fprintf(fp1, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp1, "%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp0);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }
        }else if(getArrow(args[3])){
            int symbol = getArrow(args[3]);
            if(symbol == 1) {
                char * file = args[4];
                FILE * fp;
                fp = fopen(file, "r");
                char ch[200];
                if(fp){
                    while(fscanf(fp, "%s", ch) != EOF){
                        printf("%s ", ch);
                    }
                    printf("\n");
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol == 2){
                char * file1 = args[1];
                char * file2 = args[2];
                char * file3 = args[4];
                FILE * fp1;
                fp1 = fopen(file1, "r+");
                FILE * fp2;
                fp2 = fopen(file2, "r+");
                FILE * fp3;
                fp3 = fopen(file3, "w+");
                char ch[300];
                if(fp1 && fp2 && fp3) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp3, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp3,"%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }else if(symbol ==3){
                char * file1 = args[1];
                char * file2 = args[2];
                char * file3 = args[4];
                FILE * fp1;
                fp1 = fopen(file1, "r+");
                FILE * fp2;
                fp2 = fopen(file2, "r+");
                FILE * fp3;
                fp3 = fopen(file3, "a+");
                char ch[300];
                if(fp1 && fp2 && fp3) {
                    while(fscanf(fp1, "%s", ch) != EOF){
                        fprintf(fp3, "%s ", ch);
                    }
                    while(fscanf(fp2, "%s", ch) != EOF){
                        fprintf(fp3,"%s ", ch);
                    }
                    fclose(fp1);
                    fclose(fp2);
                    fclose(fp3);
                }else {
                    printf("%s", FILE_DOESNT_EXIST);
                }
            }
        }else if(getArrow(args[4])){
            printf("Error in placement of symbol\n");
        }
    }
    else
    {
        printf("Error : Invalid number of arguments\n");
        //fflush(stdout);
        //sleep(2);
        return 0;
    }

    return 0;
}