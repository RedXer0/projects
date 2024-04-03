#include <stdio.h>

void finding_the_first_lowest_number(int array[]);

int main(){
    int array[] = {9,5,8,3,2,4,7,10,1,6};
    finding_the_first_lowest_number(array);
    return 0;
}

void finding_the_first_lowest_number(int array[]){
    int temp;
    int x;
    while(x < 8){
        if(array[0]>array[1]){
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }else{}

        if(array[1]>array[2]){
            temp = array[1];
            array[1] = array[2];
            array[2] = temp;
        }else{}

        if(array[2]>array[3]){
            temp = array[2];
            array[2] = array[3];
            array[3] = temp;
        }else{}

        if(array[3]>array[4]){
            temp = array[3];
            array[3] = array[4];
            array[4] = temp;
        }else{}

        if(array[4]>array[5]){
            temp = array[4];
            array[4] = array[5];
            array[5] = temp;
        }else{}

        if(array[5]>array[6]){
            temp = array[5];
            array[5] = array[6];
            array[6] = temp;
        }else{}

        if(array[6]>array[7]){
            temp = array[6];
            array[6] = array[7];
            array[7] = temp;
        }else{}

        if(array[7]>array[8]){
            temp = array[7];
            array[7] = array[8];
            array[8] = temp;
        } else{}

        if(array[8]>array[9]){
            temp = array[8];
            array[8] = array[9];
            array[9] = temp;
        } else{}
        x++;

    for(int i=0; i< 10; i++){
            printf("%d\n", array[i]);
    }
    }
}