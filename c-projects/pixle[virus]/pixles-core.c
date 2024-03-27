#include <stdio.h>
#include <unistd.h>
#include "pixle.c"



void creating_pixle();
void writing_pixle();
int running_pixle();

int main(){
    const int i = 1;
    while(i == 1){
        return 0;
    creating_pixle();
    writing_pixle();
    running_pixle();
    }
    return 0;
}

void creating_pixle(){
    FILE *pixle;

    pixle = fopen("/pixle.c", "w");
}

void writing_pixle(){
    FILE *pixle;

    pixle = fopen("/pixle.c", "a");

    fprintf(pixle, "#include <stdio.h>\n#include<stdlib.h>\n\nint pixle(){\nint i=1;\n\n\twhile(i ==1){\n\t\tFILE *Run;\n\t\tchar buffer[100];\n\t\tsprintf(buffer, \"/home/minny/c-projects/pixle/haha%%d.txt\",rand());\n\t\tFILE *f=fopen(buffer, \"w\");\n\t}return 0;\n}");
    fclose(pixle);
}

int running_pixle(){
    pixle();
}