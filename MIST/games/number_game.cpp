#include <iostream>


void random_nums(int arr[], int size);

void number_game(){
    int blue = 34;
    std::string ansi = "\033[";
    int points=0;
    int increase = 900;
    int turns = 50;
    int SIZE = 5;
    int numbers[SIZE];
    int your_guess;
    int i = 0;



    std::cout << ansi << blue << "m" << "Welcome to number game!" << std::endl;
    printf("the rules are simple, if you guess all the right numbers, you win!\n");

    random_nums(numbers, SIZE);

    while(turns > 0){

        printf("guess a number between 0 and 15\n");
        std::cin >> your_guess;
        if (your_guess == numbers[i]){
            printf("you got it!\n");
            points += increase + points;
            printf("your score is %d\n", points);
            i++;
        }
        else{
            printf("you got it wrong!\n");
        }
    printf("wanna try again? (y/n)\n");
    char tryagain;
    std::cin >> tryagain;
    if (tryagain != 'y' && tryagain != 'Y'){
        printf("thank you for playing!\n");
        break;
    }
    }
}

void random_nums(int arr[], int size){
    srand(time(NULL));
    int random = 0 + (rand() % 15);

    for (int i = 0; i < size; i++){

        arr[i] = 0 + (rand() % 15);
    }
}