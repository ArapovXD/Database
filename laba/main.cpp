#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "header.h"
using namespace std;


int main(int argc, char *argv[]){


    if (argc != 4){             ///Завершить программу, если поступило не 3 аргумента в мейн
        cout << "Nujno 3 argumenta! 1 - file s TV, 2 - file s holodilnikami, 3 - file s microwave\n";
        exit(0);
    }

    while (true){
        int call;
        cout << "\n1 - dobavit, 2 - izmenit parametr, 3 - udalit, 4 - naity, 0 - vihod: ";

        while (cin >> call && (call < 0 || call > 4)) cout << "Nepravilnaya komanda! Davay ewe! ";

        switch (call){
            case 0: exit(0); break;
            case 1: add(argv[1], argv[2], argv[3]); break;
            case 2: change(argv[1], argv[2], argv[3]); break;
            case 3: dell(argv[1], argv[2], argv[3]); break;
            case 4: seek(argv[1], argv[2], argv[3]); break;
        }
    }

    return 0;
}
