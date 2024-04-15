#include <iostream>
#include <string>
#include <cstdlib>
int installation(){
    FILE *install;
    install = fopen("/home/xero/.bash_aliases", "w");
    std::string files[24] = {
        "alias help_me=MIST/Mists_Out_Files/help.out",
        "alias jokes=MIST/Mists_Out_Files/jokes.out",
        "alias create=MIST/Mists_Out_Files/file_maker.out",
        "alias games=MIST/Mists_Out_Files/games.out",
        "alias seek=MIST/Mists_Out_Files/file_seeker.out",
        "alias calc=MIST/Mists_Out_Files/calculator.out",
        "alias hey=MIST/Mists_Out_Files/chat_to_mist.out",
        "alias end=\"shutdown now\"",
        "alias up=\"sudo apt update && apt upgrade\"",
        "alias s=\"sudo -s\"",
        "alias auto=MIST/Mists_Out_Files/extension_downloader.out",
        "alias mp3=MIST/Mists_Out_Files/mist_mp3.out",
        "alias bak=\"cd ../\"",
        "MIST/Mists_Out_Files/ascii_art.out",
        "alias vs=\"code\"",
        "alias tube=\"xdg-open https://www.youtube.com/\"",
        "alias gh=\"xdg-open https://github.com/\"",
        "alias fox=\"firefox\"",
        "alias cf=MIST/Mists_Out_Files/coin-flip.out",
        "alias out=MIST/Mists_Out_Files/logout.out",
        "alias Tonly=MIST/Mists_Out_Files/terminal_only.out",
        "alias gui=MIST/Mists_Out_Files/boot_into_gui.out",
        "alias clone=MIST/Mists_Out_Files/git_clone.out",
        "alias comp=MIST/Mists_Out_Files/compile.out"
    };


    for (int i = 0; i < 24; i++){
        std::string command = files[i];
        fprintf(install, "%s\n", command.c_str());
    }
    fclose(install);
    return 0;
}
