/**
 * @file rubrica.hpp
 * @brief file di definizione per classe Rubrica, struttura Node, ...
 */

#ifndef RUBRICA_HPP
#define RUBRICA_HPP

#pragma once
#include <string>

 /**
  * @brief Struttura rappresentativa di un node della lista, contenente valore e
  * puntatore al prossimo nodo
  *
  */
struct Node {
  /**
   * @brief struttura che rappresenta i campi del valore del nodo, tra essi
   * `nome`, `cognome`, `email`
   *
   */
  struct Value {
    std::string nome;
    std::string cognome;
    std::string email;
    std::string telefono;

    /**
     * @brief costruttore della struttura `Value` del nodo
     *
     * @param nome
     * @param cognome
     * @param email
     * @param telefono
     */
    Value(const std::string& nome, const std::string& cognome,
      const std::string& email, const std::string& telefono)
      : nome(nome), cognome(cognome), email(email), telefono(telefono) {
    }

    /**
     * @brief override del'operatore `==`, per confronto tra i valori dei nodi.
     *
     * @param other Altra struttura `Value` da confrontare
     * @return true - se i campi sono uguali
     * @return false - se anche solo uno è diverso
     */
    bool operator==(const Value& other) const {
      return nome == other.nome && cognome == other.cognome &&
        email == other.email && telefono == other.telefono;
    }

    // tutti i setter

    void set_nome(const std::string& nome){
      this->nome = nome;
    }

    void set_cognome(const std::string& cognome){
      this->cognome = cognome;
    }

    void set_email(const std::string& email){
      this->email = email;
    }

    void set_telefono(const std::string& telefono){
      this->telefono = telefono;
    }
  };

  Value valore;
  Node* next;

  /**
   * @brief Costruttore della struttura `Nodo`
   *
   * @param nome
   * @param cognome
   * @param email
   */
  Node(const std::string& nome, const std::string& cognome,
    const std::string& email, const std::string& telefono)
    : valore(nome, cognome, email, telefono), next(nullptr) {
  }
};

/**
 * @brief Classe rappresentativa della linked list per la rubrica.
 *
 */
class Rubrica {
  using node_type = Node;
  using node_pointer = node_type*;

private:
  node_pointer head;
  size_t __size = 0;

  /// @brief metodo che pulisce la lista senza eliminare l'oggetto
  void clear();

  /// @brief metodo che salva la lista corrente in un file CSV
  /// @param filename nome del file ("../data/rubrica.csv")
  void saveToCSV(const std::string& filename) const;

public:
  Rubrica();
  ~Rubrica();

  /**
   * @brief Metodo della classe rubrica per aggiungere un nodo in lista
   *
   * @param nome
   * @param cognome
   * @param email
   * @param telefono
   */
  void push(const std::string& nome, const std::string& cognome,
    const std::string& email, const std::string& telefono);

  /**
   * @brief metodo che ritorna la grandezza della lista
   *
   * @return constexpr size_t - `__size`
   */
  inline constexpr size_t size() const { return this->__size; }

  /**
   * @brief metodo che controlla se una lista è vuota o non
   *
   * @return true - lista vuota \n
   * @return false - lista non vuota
   */
  inline constexpr bool empty() const;

  /**
   * @brief Metodo che cerca un `Nodo` in lista
   *
   * @param nome "nome" da cercare
   * @param cognome "cognome" da cercare
   * @return true - se presente un nodo con campi specificati
   * @return false - se non presente il nodo con i campi specificati
   */
  bool search(const std::string& nome, const std::string& cognome) const;

  /**
   * @brief Metodo che elimina dalla lista un `Nodo` (se esistente)
   *
   * @param nome
   * @param cognome
   */
  void erase(const std::string& nome, const std::string& cognome);

  
  const Node& get_node_at()

  /**
   * @brief metodo che elimina tutti i Nodi doppi.
   *
   */
  void unique();

  void change_name(const std::string& nome, const std::string& cognome, const std::string& nuovo_nome);

  /**
   * @brief metodo per stampare in modo formattato la lista
   *
   */
  void print() const;
};

#endif
