#include "../include/contatto.hpp"
//#include "../include/utils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <vector>

namespace {
    bool isEmail(const std::string& email) {
        auto position = email.find('@');
        if (position == std::string::npos) return false;

        std::string domain = email.substr(position + 1);
        std::vector<std::string> allowed_domains = {
            "gmail.com",      "outlook.com",   "yahoo.com",     "hotmail.com",
            "icloud.com",     "aol.com",       "zoho.com",      "protonmail.com",
            "yandex.com",     "mail.com",      "gmx.com",       "live.com",
            "inbox.com",      "fastmail.com",  "icloud.com",    "rocketmail.com",
            "rediffmail.com", "cox.net",       "earthlink.net", "att.net",
            "verizon.net",    "sbcglobal.net", "ymail.com",     "me.com",
            "msn.com",        "bluewin.ch",    "t-online.de",   "web.de",
            "libero.it",      "alice.it",      "tin.it"
        };
        bool valid_domain = false;

        for (const std::string& allowed_domain : allowed_domains) {
            if (domain == allowed_domain) {
                valid_domain = true;
                break;
            }
        }

        return valid_domain;
    }
}

Contatto::Contatto() :
    nome_completo(""),
    telefono(""),
    email("") {
}

void Contatto::inserisci() {
    std::cout << "Inserisci il nome completo: ";
    std::getline(std::cin, nome_completo);

    std::cout << "Inserisci il numero telefonico: ";
    std::getline(std::cin, telefono);


    bool valid_email = false;
    do
    {
        std::cout << "Inserisci l'email: ";
        std::getline(std::cin, email);

        valid_email = isEmail(email);
        if (!valid_email) {
            std::cout << "Per favore inserisci una email corretta, riprova\n";
        }
    } while (!valid_email);
}

void Contatto::print() const {
    std::cout << nome_completo << "\t| " << telefono << "\t| " << email << '\n';
}


void Contatto::modifica() {
    int scelta;

    do
    {
        std::cout << "1 - Modifica il nome\n";
        std::cout << "2 - Modifica il numero di telefono\n";
        std::cout << "3 - Modifica la email\n";
        std::cout << "0 - Uscire dal menu\n";

        std::cout << "Scelta: ";
        std::cin >> scelta;
        std::cin.ignore();

        switch (scelta)
        {
        case 1: {
            std::cout << "Nuovo nome (attuale: " << nome_completo << "): ";
            std::getline(std::cin, nome_completo);
            break;
        }
        case 2: {
            std::cout << "Nuovo numero di telefono (attuale: " << telefono << "): ";
            std::getline(std::cin, telefono);
            break;
        }
        case 3: {
            std::cout << "Nuova email (attuale: " << email << "): ";
            std::getline(std::cin, email);
            break;
        }
        case 0:
            std::cout << "Uscita...\n";
            break;
        default:
            if (scelta != 0) {
                std::cout << "Opzione inesistente, riprova\n";
            }
            break;
        }
    } while (scelta != 0);

}

const std::string& Contatto::get_nome() const { return nome_completo; }
const std::string& Contatto::get_telefono() const { return telefono; }
const std::string& Contatto::get_email() const { return email; }

std::string Contatto::to_csv() const {
    return nome_completo + "," + telefono + "," + email;
}

void Contatto::from_csv(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, nome_completo, ',');
    std::getline(ss, telefono, ',');
    std::getline(ss, email, ',');
}