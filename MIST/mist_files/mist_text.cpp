#include <iostream>


void ascii_art();
int main(){
    ascii_art();
    return 0;

}

void ascii_art(){
    std::string mist[13] = {
" ███▄ ▄███▓ ██▓  ██████ ▄▄▄█████▓",
"▓██▒▀█▀ ██▒▓██▒▒██    ▒ ▓  ██▒ ▓▒",
"▓██    ▓██░▒██▒░ ▓██▄   ▒ ▓██░ ▒░",
"▒██    ▒██ ░██░  ▒   ██▒░ ▓██▓ ░ ",
"▒██▒   ░██▒░██░▒██████▒▒  ▒██▒ ░ ",
"░ ▒░   ░  ░░▓  ▒ ▒▓▒ ▒ ░  ▒ ░░   ",
"░  ░      ░ ▒ ░░ ░▒  ░ ░    ░    ",
"░      ░    ▒ ░░  ░  ░    ░      ",
"       ░    ░        ░           "
};

for (int i = 0; i < 13; i++){
    int ansi_colors = 36;
    std::string colors = "\033[";
    std::cout << colors << ansi_colors << "m" << mist[i] << "\033" << std::endl;
    }
}