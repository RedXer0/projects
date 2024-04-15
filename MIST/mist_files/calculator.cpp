#include <iostream>
#include <string>
#include <cstdlib>

void addition();
void subtraction();
void multiply();
void divide();
int main(){
    int response;
    std::string operations[] = {
    "1. Add",
    "2. Subtract",
    "3. Multiply",
    "4. Divide",
    "5. Exit"
    };
    int ansi_colors = 34;
    std::string colors = "\033[";
    for(int i = 0; i < 5; i++){
        std::cout << colors << ansi_colors << "m" << operations[i] << "\033" << std::endl;
        printf("|-----------\n");
    }
    std::cin >> response;

    switch(response){
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            exit(0);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }
    return 0;
}

void addition(){
    int num1, num2;
    printf("Enter the 2 numbers you would like to add\n");
    std::cin >> num1;
    printf("+\n");
    std::cin >> num2;
    printf("=\n");
    int result = num1 + num2;
    printf("%d\n", result);
}

void subtraction(){
    int num1, num2;
    printf("Enter the 2 numbers you would like to subtract\n");
    std::cin >> num1;
    printf("-\n");
    std::cin >> num2;
    printf("=\n");
    int result = num1 - num2;
    printf("%d\n", result);
}

void multiply(){
    int num1, num2;
    printf("Enter the 2 numbers you would like to multiply\n");
    std::cin >> num1;
    printf("x\n");
    std::cin >> num2;
    printf("=\n");
    int result = num1 * num2;
    printf("%d\n", result);
}

void divide(){
    int num1, num2;
    printf("Enter the 2 numbers you would like to divide\n");
    std::cin >> num1;
    printf("/\n");
    std::cin >> num2;
    printf("=\n");
    double result = num1 / num2;
    printf("%.2f\n", result);
}