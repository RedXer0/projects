#include <iostream>

int main(){
    printf("\033[91m logging out of session!\n");
    system("xfce4-session-logout --logout");
    return 0;
}