#include "../include/list.hpp"
#include "../include/utils.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>

namespace {
    Nodo* merge(Nodo* left, Nodo* right) {
        if (!left) return right;
        if (!right) return left;


        if (left->contatto.get_nome() < right->contatto.get_nome()) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    void split(Nodo* head, Nodo** left, Nodo** right) {
        if (!head || !head->next) {
            *left = head;
            *right = nullptr;
            return;
        }

        Nodo* slow = head;
        Nodo* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        *left = head;
        *right = slow->next;
        slow->next = nullptr;
    }

    Nodo* merge_sort(Nodo* head) {
        if (!head || !head->next) return head;

        Nodo* left;
        Nodo* right;
        split(head, &left, &right);

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
}

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
    //FIXME   se si della linee di codice commentate togliete i commenti 
    //          verrà stampata la lettere iniziale del contatto dopo il sort() 

    if (!head) {
        std::cout << "La rubrica è vuota.\n";
        return;
    }

    const_cast<List*>(this)->sort();

    std::vector<std::vector<std::string>> dati;
    dati.push_back({ "Nome", "Telefono", "Email" }); // Intestazione della tabella

    Nodo* temp = head;
    //char letteraCorrente = '\0'; // Iniziale attuale

    while (temp) {
        //char primaLettera = std::toupper(temp->contatto.get_nome()[0]);

        /*if (primaLettera != letteraCorrente) {
            if (letteraCorrente != '\0') dati.push_back({ "", "", "" });
            dati.push_back({ std::string(1, primaLettera), "", "" });
            letteraCorrente = primaLettera;
        }*/

        dati.push_back({ temp->contatto.get_nome(), temp->contatto.get_telefono(), temp->contatto.get_email() });

        temp = temp->next;
    }

    stampaTabella(dati);
}



void List::find() const {
    if (!head) {
        std::cerr << "La rubrica è vuota.\n";
        return;
    }

    const_cast<List*>(this)->sort();

    std::string prefix;
    std::cout << "Cerca: ";
    std::getline(std::cin, prefix);
    
    std::string prefix_lower = prefix;
    std::transform(prefix_lower.begin(), prefix_lower.end(), prefix_lower.begin(), ::tolower);

    Nodo* curr = head;
    bool found = false;

    while(curr){
        std::string nome = curr->contatto.get_nome();
        std::string nome_lower = nome;
        std::transform(nome_lower.begin(), nome_lower.end(), nome_lower.begin(), ::tolower);

        if(nome_lower.find(prefix_lower) == 0 || nome_lower.find(prefix_lower) != std::string::npos){
            curr->contatto.print();
            found = true;
        }
        
        curr = curr->next;
    }

    if(!found){
        std::cout << "Nessun contatto trovato con '" << prefix << "'\n";
    }
}

void List::sort() {
    head = merge_sort(head);
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
    Nodo* tmp = nullptr;

    do {
        std::cout << "Nome del contatto da modificare (0 per annullare): ";
        std::getline(std::cin, nome);

        if (nome == "0") {
            std::cout << "Operazione annullata.\n";
            return;
        }

        tmp = head;
        while (tmp) {
            if (tmp->contatto.get_nome() == nome) {
                tmp->contatto.modifica();
                salva_su_file();
                std::cout << "Contatto modificato con successo e salvato su file.\n";
                return;
            }
            tmp = tmp->next;
        }

        std::cout << "Contatto non trovato. Riprova.\n";
    } while (true);
}



void List::salva_su_file() const {
    std::ofstream file("contatti.csv");
    Nodo* tmp = head;
    while (tmp) {
        file << tmp->contatto.to_csv() << "\n";
        tmp = tmp->next;
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