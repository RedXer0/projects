#include <stdio.h>

int main(){
    FILE *file;
    char buffer[1000];
    char directory[200];
    char myinpt[500];
    char file_extension[6];
    printf("enter your directory: ");
    scanf("%s", directory);
    printf("type in your file name\n");
    scanf("%s", myinpt);
    printf("type in your file extension\n");
    scanf("%s", file_extension);
    sprintf(buffer, "%s/%s.%s", directory,myinpt,file_extension);
    FILE *f = fopen(buffer, "w");
    fclose(f);
    return 0;
}