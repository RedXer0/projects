/*
Mist the terminal assistant.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <istream>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>

void mist_questions();
void computer_specs();
void list_of_tasks();

void date_and_time();

void computer_jokes();

void opening_vscode();

void opening_firefox();

void opening_github();

void opens_file();

void shutdown();

void exiting();

void time_delay();

void update_upgrade();

int main(void){
    update_upgrade();
    int choice;
    std::cout << "greetings [name/username] what would you like to do?" << std::endl;
    mist_questions();
    std::cin >> choice;

    if(choice == 1){
        computer_jokes();
    }
    if (choice == 2){
        computer_specs();
    }
    else if (choice == 3){
        date_and_time();
    }
    else if (choice == 4){
        list_of_tasks();
    }
    else if (choice == 5){
        opening_vscode();
    }
    else if (choice == 6){
        opening_firefox();
    }
    else if(choice == 7){
        opening_github();
    }
    else if (choice == 8){
        opens_file();
    }
    else if (choice == 9){
        std::cout << "goodbye [insert your name/username]" << std::endl;
        time_delay();
        shutdown();
    }
    else if (choice == 10){
        std::cout << "bye [insert your name/username]" << std::endl;
        exiting();
    }
    else{
        exit(0);
    }

    while(true){
        char decide;
        std::cout << "would you like to choose more tasks? y/n: " << std::endl;
        std::cin >> decide;

        if(decide == 'y' || decide == 'Y'){
            main();
        } else { break;}
    }
    return 0;
}

void time_delay(){
    int minumum_value = 0;
    int maximum_value = 5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minumum_value, maximum_value);
    int random_number = dis(gen);

    std::chrono::seconds delay(5);
        auto start_time = std::chrono::high_resolution_clock:: now();
        while (std::chrono::high_resolution_clock::now() - start_time < delay){

        }
}

void computer_specs(){
    // shows system specs
    system("neofetch --stdout");

}
void mist_questions(){
    // system questions list.
    std::string tasks[10] = {"1. Tell a random joke.", "2. check system specs.", "3. give the date and time.", "4. make a lists of tasks for you.", "5. open vscode.", "6. open firefox.", "7. open github.", "8. open files.", "9. shutdown system.", "10. exit."};

    for (int i = 0; i < 10; i++){
        std::cout << tasks[i] << std::endl;
    }
}

void date_and_time(){
    //prints date and time
    system("date");
}


void computer_jokes() {
    // number within range generator.
    int minumum_value = 0;
    int maximum_value = 5;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minumum_value, maximum_value);
    int random_number = dis(gen);

    //list of jokes and punchlines.
    std::string jokes[6] ={"Whats black white and red all over?", "what do you call a blank photo?", "what is the difference between old cheese and fresh cheese", "what do you call a powerless generator?", "what do you call a computer with no memory?", "knock knock."};
    std::string punchlines[6] = {"A 1950s crime scene.", "A blind mans perspective.", "when you eat fresh cheese you want the but mold when you eat old cheese you dont.", "idk ask the generator.", "a waste of money.", "java"};

    std::string response;
    std::cout << jokes[random_number] << std::endl;
    std::cin >> response;
    if (jokes[random_number] == jokes[5]){ // delays for this joke only.
        std::chrono::seconds delay(5);
        auto start_time = std::chrono::high_resolution_clock:: now();
        while (std::chrono::high_resolution_clock::now() - start_time < delay){

        }
        std::cout << punchlines[random_number] << std::endl;
    }
    else{
        std::cout << punchlines[random_number] << std::endl;
    }

}

void list_of_tasks(){
    // allows user to insert filename and extension.
    std::string filename;
    std::cout << "insert name of file and extension: " << std::endl;
    std::cin >> filename;

    // opens the file for writing.
    std::ofstream file(filename);

    // checks if file has been opened.
    if (!file.is_open()){
        std::cerr << "error opening file." << std::endl;
    }

    //writes text to file.
    while(true){
        std::string tasks;
        std::cout << "insert your tasks: " << std::endl;
        std::cin >> tasks;


        //checks if user wants to exit.
        file << tasks << std::endl;
        std::string response;
        std::cout << "would you like to add another task? y/n:" << std::endl;
        std::cin >> response;
        if (response == "y"){
            continue;
        }
        else if (response == "n"){
            break;
        }
    }
    file.close();
}

void opening_vscode(){
    //opens vscode.
    system("code");
}

void opening_firefox(){
    //opens firefox.
    system("firefox");
}

void opening_github(){
    //opens github.
    system("xdg-open https://github.com/");
}

void opens_file(){
    // opens file by specified name.
    std::string filename;
    std::string editor;
    std::string file_location;
    std::cout << "insert file location: " << std::endl;
    std::cin >> file_location;
    std::cout << "insert filename and extension: " << std::endl;
    std::cin >> filename;
    std::cout << "enter your file editor: " << std::endl;
    std::cin >> editor;
    system((editor + " " + file_location + filename).c_str()); 
}

void shutdown(){
    //shutsdown system.
    system(" shutdown now");
}

void exiting(){
    //exits terminal assistant.
    system("exit");
}


void update_upgrade(){
    system("sudo apt update && apt upgrade");
}