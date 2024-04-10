/*
this was the most annoying one to do and it's not even fully done yet.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

void tic_tac_toe();
void guess_the_number();
void guess_the_word();
void gamble();
void game_list();
int games(){
    int which_one;
    std::string username;
    printf("what would you like to be called?\n");
    std::cin >> username; //gets your name
    std::cout << "hello" << username << std::endl;
    std::cout << "what game do you want to play?" << std::endl;
    game_list(); // prints list function
    std::cin >> which_one; // takes user input
    switch(which_one == 1){
        case 1:
            guess_the_number(); // goes to number guessing game if you choose 1
            break;
        case 2:
            guess_the_word(); // goes to word guessing game if you pick 2
            break;
        case 3:
            gamble(); // goes to gambling game if you pick 3
            break;
        default:
            printf("no valid input now leaving\n"); // exits if you type in anything else.
            break;
    }
    return 0;
}


// prints the list of games
void game_list(){
    std::string list_of_games[3] = {"1. guess the number\n", "2. guess the word\n","3. gamble\n"};

    for (int i = 0; i < 3; i++){
        std::cout << list_of_games[i] << std::endl;
    }
}


// gambling game
void gamble(){
    int money = 10000; // gives you 10000 "money" to start off
    int bet; // bet value
    while(money > 0){

        std::cout << "welcome you have :" << money << " in your account" << std::endl;
        std::cout << "enter your bet ammount" << std::endl;
        std::cin >> bet; // bet amount input

        srand(time(NULL));
        int result = rand() % 3 + 1; // random number generator
        printf(" %d\t%d\t%d\t\m", result); // prints numbers to screen lol

        if (result == 1){ // kinda explains it's self lol
            std::cout << "you won $" << bet * 2 << "!" << std::endl;
            money += bet * 2;
        }
        else{
            std::cout << "you lost $" << bet << "!" << std::endl;
            money -= bet;
        }
        char answer;
        std::cout << "would you like to play again? y/n" << std::endl;
        std::cin >> answer;
        if (answer == 'y' || answer == 'Y'){
            continue;
        } else {break;}
    }
}


// word guessing game
void guess_the_word(){
    std::string words[9] = {"apple", "cat", "dictionary", "summon", "bacon", "terminator", "computer", "knife", "Mist"};
    int guesses = 5;
    
    while(guesses > 0){

        srand(time(NULL));
        int word_number = rand() % 9;


        std::string guess;
        char answer;
        printf("guess the word\n");
        std::cin >> guess;
        guesses -= 1;
        printf("current guesses left: %d\n", guesses);
        if (guess == words[word_number]){
            printf("you got it\n");
        }
        if (guess != words[word_number] && guesses == 0){
            printf("you got it wrong\n");
            std::cout << "the word was: " << words[word_number] << std::endl;
        }
        if (guesses == 0 || guess != words[word_number] && guesses == 0 || guess == words[word_number]){
            printf("wanna play again? y/n\n");
            char answer;
            std::cin >> answer;
            if (answer == 'y' || answer == 'Y'){
                guesses = 5;
            }
            else{
                break;
            }
        }
    }
}


// unfair number guessing game
void guess_the_number(){
    int user_number;
    int guesses = 10;
    int number;

    while (guesses > 0){
        srand(time(NULL));
        int random_num_generator = rand() % 20;
        number = random_num_generator;

        printf("im thinking of a number between 1 and 20\n");
        std::cin >> user_number;
        guesses -= 1;
        printf("current guesses left: %d\n", guesses);
        if (user_number == number){
            printf("wow you're incredible\n");
            std::cout << "the number was: " << number << std::endl;
        }
        if (user_number != number){
            printf("sorry wrong number try again\n");
            if (guesses == 0){
                printf("the right number was: %d\n", number);
            }
        }
        if (guesses == 0 && user_number != number || user_number == number){
            printf("wanna play again? y/n\n");
            char answer;
            std::cin >> answer;
            if (answer == 'y' || answer == 'Y'){
                guesses = 10;
            }
            else {
                break;
            }
        }
    }
}
