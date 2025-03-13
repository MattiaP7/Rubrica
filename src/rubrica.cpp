#include "../include/rubrica.hpp"
#include "../include/utils.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#define RUBRICA_CSV_PATH "C:/Users/PIRAZZI.8076/OneDrive - I.I.S. Bassi-Burgatti/anno scolastico 2024 2025 4n/informatica/Rubrica/data/rubrica.csv"

void Rubrica::clear() {
  while (head != nullptr) {
    node_pointer temp = head;
    head = head->next;
    delete temp;
  }
  __size = 0;
}

void Rubrica::saveToCSV(const std::string& filename) const {
  std::ofstream file(RUBRICA_CSV_PATH);

  if (!file.is_open()) {
    std::cerr << "Errore nell'aprire il file: " << RUBRICA_CSV_PATH << std::endl;
    return;
  }

  node_pointer current = head;
  while (current) {
    file << current->valore.nome << "," << current->valore.cognome << ","
      << current->valore.email << "," << current->valore.telefono << "\n";
    current = current->next;
  }
}

Rubrica::Rubrica() : head(nullptr), __size(0) {}

Rubrica::~Rubrica() { clear(); }

void Rubrica::push(const std::string& nome, const std::string& cognome,
  const std::string& email, const std::string& telefono) {
  // Controllo per evitare duplicati
  node_pointer temp = head;
  while (temp) {
    if (temp->valore.nome == nome && temp->valore.cognome == cognome &&
      temp->valore.telefono == telefono) {
      return;
    }
    temp = temp->next;
  }

  // funzione che controlli se una email sia valida
  // vorrei farlo anche per il numero di telefono ma diventerebbe difficile
  //if(!isEmail(email)){
  //  std::cerr << "La email inserita: " << email << " non è valida\n";
  //  return;
  //} 
  assert(isEmail(email));

  // Creazione del nodo
  node_pointer nuovoNodo = new Node(nome, cognome, email, telefono);
  if (!nuovoNodo) {
    std::cerr << "Errore: memoria insufficiente!" << std::endl;
    return;
  }

  // Inserimento ordinato
  if (!head || nome < head->valore.nome ||
    (nome == head->valore.nome && cognome < head->valore.cognome) ||
    (nome == head->valore.nome && cognome == head->valore.cognome &&
      telefono < head->valore.telefono)) {
    nuovoNodo->next = head;
    head = nuovoNodo;
  }
  else {
    node_pointer curr = head;
    while (curr->next && (curr->next->valore.nome < nome ||
      (curr->next->valore.nome == nome &&
        curr->next->valore.cognome < cognome) ||
      (curr->next->valore.nome == nome &&
        curr->next->valore.cognome == cognome &&
        curr->next->valore.telefono < telefono))) {
      curr = curr->next;
    }
    nuovoNodo->next = curr->next;
    curr->next = nuovoNodo;
  }

  ++__size;
  saveToCSV(RUBRICA_CSV_PATH);

  // Chiamiamo unique solo quando ci sono più di un 1 elemento
  if (__size > 1)
    this->unique();
}

bool Rubrica::search(const std::string& nome,
  const std::string& cognome) const {
  node_pointer temp = head;
  while (temp) {
    if (temp->valore.nome == nome && temp->valore.cognome == cognome) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void Rubrica::erase(const std::string& nome, const std::string& cognome) {
  if (!head)
    return;

  if (head->valore.nome == nome && head->valore.cognome == cognome) {
    node_pointer temp = head;
    head = head->next;
    delete temp;
    --__size;
    saveToCSV(RUBRICA_CSV_PATH);
    return;
  }

  node_pointer prev = nullptr;
  node_pointer curr = head;

  while (curr) {
    if (curr->valore.nome == nome && curr->valore.cognome == cognome) {
      if (prev) {
        prev->next = curr->next;
      }
      delete curr;
      --__size;
      saveToCSV(RUBRICA_CSV_PATH);
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

void Rubrica::unique() {
  if (!head)
    return;

  node_pointer curr = head;
  while (curr && curr->next) {
    if (curr->valore.nome == curr->next->valore.nome &&
      curr->valore.cognome == curr->next->valore.cognome &&
      curr->valore.email == curr->next->valore.email &&
      curr->valore.telefono == curr->next->valore.telefono) {
      node_pointer temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
      --__size;
    }
    else {
      curr = curr->next;
    }
  }
}

void Rubrica::print() const {
  if (this->empty()) {
    std::cout << "La rubrica è vuota." << std::endl;
    return;
  }

  node_pointer current = head;
  size_t index = 1;

  while (current != nullptr) {
    std::cout << "Contatto #" << index++ << "\n";
    std::cout << "Nome: " << current->valore.nome << "\n";
    std::cout << "Cognome: " << current->valore.cognome << "\n";
    std::cout << "Email: " << current->valore.email << "\n";
    std::cout << "Telefono: " << current->valore.telefono << "\n";
    std::cout << "--------------------------" << std::endl;
    current = current->next;
  }
}

void Rubrica::change_name(const std::string& nome, const std::string& cognome, const std::string& nuovo_nome){
  bool search_contatto = Rubrica::search(nome, cognome);

  if(search_contatto){
    
  }
}

inline constexpr bool Rubrica::empty() const { return head == nullptr; }
