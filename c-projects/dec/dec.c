#include <stdio.h>
#include <stdlib.h>


void sortA(int a[]);
void sortB(int a[]);

int main(){
    int a[4]={9,8,7,6};
    sortA(a);
    sortB(a);
    // prints out all numbers in the array after executing the 2 functions
    for(int i=0; i<4; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

void sortA(int a[]){
    // compares 9 to 6 and if 9 is greater than 6 it swaps places with 6
    if(a[0]>a[3]){
        int temp;
        temp = a[0];
        a[0] = a[3];
        a[3] = temp;
    }
}

void sortB(int a[]){
    // compares 8 to 7 and if 8 is greater than 7 it swaps places with 7
    if(a[1]>a[2]){
    int temp;
    temp = a[1];
    a[1] = a[2];
    a[2] = temp;
     }
}