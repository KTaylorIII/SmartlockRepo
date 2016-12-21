#include <iostream>
#include "Controller.h"

/*
 AUTHOR: Kent Taylor
 MAINTAINER: Kent Taylor
 LICENSE: MIT

 BY COMPILING, USING, OR OTHERWISE DISTRIBUTING THIS SOURCE CODE, YOU AGREE TO THE TERMS STIPULATED IN THE LICENSE AGREEMENT.
 */ 

int main(int argc, const char* argv[]){
    if (argc != 2){
        std::cout << "Usage: smartlock [lock][unlock]\n";
        return -1;
    }
    std::string buffer = "";
    for (int pos = 0; argv[1][pos] != '\0'; pos++){
        buffer += argv[1][pos];
    }
    if (buffer != "unlock" && buffer != "lock"){
        std::cout << "Usage: smartlock [lock][unlock]\n";
        return -1;
    }
    Controller vc = Controller();
    if (buffer == "unlock"){
        vc.unlock();
    }
    if (buffer == "lock"){
        vc.lock();
    }
    
    return 0;
}
