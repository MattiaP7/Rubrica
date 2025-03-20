#include "include/rubrica.hpp"
#include <iostream>

void Rubrica::Applicazione() {
    int scelta;
    do {
        std::cout << "\n--- Rubrica ---\n";
        std::cout << "1 - Aggiungi contatto\n";
        std::cout << "2 - Mostra contatti\n";
        std::cout << "3 - Cerca contatto\n";
        std::cout << "4 - Modifica contatto\n";
        std::cout << "5 - Elimina contatto\n";
        std::cout << "0 - Esci\n";
        std::cout << "Scelta: ";
        std::cin >> scelta;
        std::cin.ignore();

        switch (scelta) {
        case 1: 
            lista.push();
            break;
        case 2: 
            lista.mostra();
            break;
        case 3: 
            lista.find();
            break;
        case 4: 
            lista.modifica();
            break;
        case 5: 
            lista.erase();
            break;
        case 0: 
            std::cout << "Uscita...\n"; 
            std::exit(1);
        default: 
            if (scelta != 0) { 
                std::cout << "Scelta non valida.\n"; 
            } 
            break;
        }
    } while (scelta != 0);
}
