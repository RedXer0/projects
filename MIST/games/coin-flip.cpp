#include <iostream>
#include <time.h>


int main(){
    srand(time(NULL));
    int tails=0;
    int heads=1;
    bool flip = rand() % 3;
    char your_input;
    flip = rand() % 3;
    if(flip == 3){
        flip = rand() % 2;
    }
    if(flip == 0){
        printf("\033[34m it landed on: Heads!\n");
        tails++;
    }
    else{
        printf("\033[92m it landed on: Tails!\n");
        heads++;
    }
}
