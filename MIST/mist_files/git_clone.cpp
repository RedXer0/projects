#include <iostream>

int main(){
    std::string user;
    printf("enter user you would like to clone: ");
    std::cin >> user;
    std::string file;
    printf("enter file you would like to clone: ");
    std::cin >> file;
    std::string combined = "git clone https://github.com/" + user + "/" + file + ".git";
    system(combined.c_str());
}