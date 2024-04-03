#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("my percentage calculator\n");
    int numA; // second integer
    int numB; // first integer


    printf("insert the first number.\n");
    scanf("%d", &numA); //takes user input then gives numA the value of the input
    printf("enter the second number.\n");
    scanf("%d", &numB);

    if(numA > numB){
        float sum = ((float)numB/numA)*100;
        printf("numB: %d. numA: %d. sum of the 2 in percentage: %.2f%%\n", numA, numB, sum);
    }
    else if(numB > numA){
        float sum = ((float)numA/numB)*100;
        printf("numA: %d. numB: %d. sum of the 2 in percentage: %.2f%%\n", numA, numB, sum);
    }


    return 0;
}