#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

void slot_machine(){
    int A;
    int B;
    int C;
    int money = 30000;
    int color = 34;
    int bet;
    std::string ansi_color = "\033[";

    srand(time(NULL));

    while (money > 0){
        std::cout << ansi_color << color << "m" << "Your current amount is: " << money << "$" << std::endl;
        A = rand() % 3+1;
        B = rand() % 3+1;
        C = rand() % 3+1;

        std::cout << ansi_color << color << "m" << "enter your bet" << std::endl;
        std::cin >> bet;
        printf("%d %d %d\n", A, B, C);

        if (A == B && B == C && A < 3 && B < 3 && C < 3){
            money = money + bet + bet;
            printf("you won: %d\n", bet+bet);
        }
        else if (A == 3 && B == 3 && C == 3 && A == 3 && B == 3 && C == 3){
            money = money + bet * bet;
            printf("you won: %d\n", bet*bet);
        }
        else{
            std::cout << ansi_color << color << "m" << "you lost " << bet << "$" << std::endl;
            money = money - bet;
        }

        if (money <=0){
            printf("you ran out of money lol\n");
            break;
        }

        char unimportant_char;
        printf("wanna play again? (y/n): ");
        std::cin >> unimportant_char;
        switch(unimportant_char){
            case 'y':
                break;
            case 'n':
                exit(0);
                break;
            default:
            printf("invalid input\n");
            exit(0);
            break;
        }
    }
}