#include <iostream>

int main(){
    std::string file_type;
    std::string out_file;
    std::string file;
    char run;



    printf("\033[34m Is it a cpp file or c file?: ");
    std::cin >> file_type;


    if (file_type == "cpp"){
        printf("Enter executable file name: ");
        std::cin >> out_file;
        printf("Enter main file name: ");
        std::cin >> file;
        std::string combined = "g++ -o" + out_file + ".out" + " " + file + ".cpp";
        system(combined.c_str());
        printf("\033[34m your file has been compiled succesfully or if theres errors might wanna fix them\n");
        printf("\033[34m wanna run your file? (y/n): ");
        std::cin >> run;
        while (run == 'y' || run == 'Y'){
            printf("\033[34m running your file\n");
            std::string output = "./" + out_file + ".out";
            system(output.c_str());
            break;
            exit;
        }
    }
    else if (file_type == "c"){
        printf("Enter executable file name: ");
        std::cin >> out_file;
        printf("Enter main file name: ");
        std::cin >> file;
        std::string combined = "gcc -o" + out_file + ".out" + " " + file + ".c";
        system(combined.c_str());
        printf("\033[34m your file has been compiled succesfully or if theres errors might wanna fix them\n");
        printf("\033[34m wanna run your file? (y/n): ");
        std::cin >> run;
        while (run == 'y' || run == 'Y'){
        printf("\033[34m running your file\n");
        std::string output = "./" + out_file + ".out";
        system(output.c_str());
        break;
        exit;
        }
    }
    else{
        printf("if you use a different file type, you'll have to edit the compile_c++.cpp file\n");
        exit(0);
    }
    return 0;
}