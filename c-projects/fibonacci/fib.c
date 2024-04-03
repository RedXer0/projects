#include <stdio.h>

int main(){
    float x = 0;
    float y = 1;
    float z;
    int i = 0;
    while (i < 50){
        z = x+y;
        x = z;
        y = x;
        i++;
        printf("%.2f\n", z);
    }
    return 0;
}