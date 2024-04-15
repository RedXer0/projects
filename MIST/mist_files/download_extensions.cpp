#include <iostream>

int main(){
    int ansi_colors = 34;
    std::string colors = "\033[";
    std::string extemsion_name;
    std::cout << colors << ansi_colors << "m" << "Enter extension name: " << std::endl;
    std::cin >> extemsion_name;
    system(("sudo apt-get install " + extemsion_name).c_str());

    return 0;
}