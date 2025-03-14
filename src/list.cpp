#include "../include/list.hpp"
#include <iostream>
#include <fstream>

Nodo::Nodo() : next(nullptr) {}

List::List() : head(nullptr), M_size(0) {
    carica_da_file();
}

List::~List() {
    Nodo* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    M_size = 0;
}


void List::push() {
    Nodo* new_node = new Nodo();
    if (!new_node) {
        std::cerr << "ERRORE: memoria insufficiente!\n";
        return;
    }


    new_node->contatto.inserisci();

    // Controlliamo per evitare di inserire duplicati
    Nodo* tmp = head;
    while (tmp) {
        if (
            tmp->contatto.get_nome() == new_node->contatto.get_nome() &&
            tmp->contatto.get_telefono() == new_node->contatto.get_telefono() &&
            tmp->contatto.get_email() == new_node->contatto.get_email()
            ) {
            delete new_node;
            return;
        }
        tmp = tmp->next;
    }


    // facciamo un inserimento ordinato
    if (!head || head->contatto.get_nome() > new_node->contatto.get_nome()) {
        new_node->next = head;
        head = new_node;
    }
    else {
        Nodo* current = head;
        while (current->next && current->next->contatto.get_nome() < new_node->contatto.get_nome()) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }


    M_size++;
    salva_su_file();

    if (M_size > 1) {
        this->unique();
    }
}

void List::mostra() const {
    Nodo* temp = head;
    while (temp) {
        temp->contatto.print();
        temp = temp->next;
    }
}

void List::find() const {
    std::string nome_completo;
    std::cout << "Nome da cercare: ";
    std::getline(std::cin, nome_completo);

    Nodo* tmp = head;
    while (head) {
        if (tmp->contatto.get_nome() == nome_completo) {
            tmp->contatto.print();
            return;
        }
        tmp = tmp->next;
    }
    std::cout << "Contatto non trovato\n";
}

void List::erase() {
    std::string nome;
    std::cout << "Nome da cercare: ";
    std::getline(std::cin, nome);

    if (!head) return;

    if (head->contatto.get_nome() == nome) {
        Nodo* tmp = head;
        head = head->next;
        delete tmp;
        --M_size;
        salva_su_file();
        return;
    }

    Nodo* prev = nullptr;
    Nodo* curr = head;

    while (curr) {
        if (curr->contatto.get_nome() == nome) {
            if (prev) {
                prev->next = curr->next;
            }
            delete curr;
            --M_size;
            salva_su_file();
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void List::unique() {
    if (!head) return;

    Nodo* curr = head;
    while (curr && curr->next) {
        if (
            curr->contatto.get_nome() == curr->next->contatto.get_nome() &&
            curr->contatto.get_telefono() == curr->next->contatto.get_telefono() &&
            curr->contatto.get_email() == curr->next->contatto.get_email()
            ) {
            Nodo* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            --M_size;
        }
        else {
            curr = curr->next;
        }
    }
}

constexpr size_t List::get_size() { return M_size; }

void List::modifica() {
    std::string nome;
    std::cout << "Nome del contatto da modificare: ";
    std::getline(std::cin, nome);

    Nodo* temp = head;
    while (temp) {
        if (temp->contatto.get_nome() == nome) {
            temp->contatto.modifica();
            salva_su_file();
            return;
        }
        temp = temp->next;
    }
    std::cout << "Contatto non trovato.\n";
}

void List::salva_su_file() const {
    std::ofstream file("contatti.csv");
    Nodo* temp = head;
    while (temp) {
        file << temp->contatto.to_csv() << "\n";
        temp = temp->next;
    }
}

void List::carica_da_file() {
    std::ifstream file("contatti.csv");
    std::string line;

    while (std::getline(file, line)) {
        Nodo* new_node = new Nodo();
        new_node->contatto.from_csv(line);
        new_node->next = head;
        head = new_node;
    }
}