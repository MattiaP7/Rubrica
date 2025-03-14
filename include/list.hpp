#ifndef LISTA_HPP
#define LISTA_HPP

#pragma once
#include "contatto.hpp"

/**
 * @brief strutta per rappresentare un nodo della lista
 *
 */
struct Nodo {
    Contatto contatto;
    Nodo* next;

    Nodo();
};

/**
 * @brief classe List
 *
 */
class List {
private:
    Nodo* head; // puntatore alla testa della lista

    /**
     * @brief quando si crea/elimina un contatto viene chiamato questo metodo che aggiorna il file .csv
     *
     */
    void salva_su_file() const;
    size_t M_size = 0; // tiene traccia della grandezza della lisat

public:
    /// @brief costruttore di default
    List();
    /// @brief distruttore di default
    ~List();

    /// @brief metodo per l'inserimento in testa di un nodo nella lista, verifica che non ci siano nodi uguali e fa un inserimento ordinato
    void push();

    /// @brief metodo che mostra tutti i contatti della rubrica
    void mostra() const;

    /// @brief metodo per cercare un contatto nella rubrica
    void find() const;

    /// @brief metodo per eliminare un contatto della rubrica
    void erase();

    /// @brief metodo che elimina tutti i contatti uguali
    void unique();

    /// @brief metodo per ritornare la dimensione della lista
    /// @return size_t - grandezza della lista
    constexpr size_t get_size();

    /// @brief metodo per modifica un conttatto della rubrica
    void modifica();

    /**
     * @brief metodo che carica i dati del file csv alla lista
     *
     */
    void carica_da_file();
};

#endif