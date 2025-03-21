#ifndef LISTA_HPP
#define LISTA_HPP

#pragma once
#include "contatto.hpp"
#include "utils.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @struct Nodo
 * @brief Struttura che rappresenta un nodo della lista concatenata.
 */
struct Nodo {
    Contatto contatto; ///< Contatto memorizzato nel nodo
    Nodo* next;        ///< Puntatore al nodo successivo nella lista

    /**
     * @brief Costruttore di default del nodo.
     *
     * Inizializza il puntatore `next` a `nullptr`.
     */
    Nodo();
};

/**
 * @class List
 * @brief Classe che implementa una lista concatenata per gestire i contatti della rubrica.
 */
class List {
private:
    Nodo* head;         ///< Puntatore alla testa della lista
    size_t M_size = 0;  ///< Numero di elementi presenti nella lista

    /**
     * @brief Salva i dati della lista su un file CSV.
     *
     * Questo metodo viene chiamato automaticamente quando si aggiunge, modifica o rimuove un contatto.
     */
    void salva_su_file() const;

public:
    /**
     * @brief Costruttore di default della lista.
     *
     * Inizializza la lista come vuota.
     */
    List();

    /**
     * @brief Distruttore della lista.
     *
     * Libera la memoria deallocando tutti i nodi della lista.
     */
    ~List();

    /**
     * @brief Inserisce un nuovo contatto nella lista, viene fatto un inserimento in testa per poi fare una chiamata alla funzione `List::sort()` per ordinare in ordine alfabetico, se il contatto esiste già, non verrà inserito.
     */
    void push();

    /**
     * @brief Mostra tutti i contatti presenti nella rubrica.
     */
    void mostra() const;

    /**
     * @brief Cerca contti nella rubrica, troverà tutti i contatti che inziano con la query MA ANCHE tutti i contatti che contengono la query 
     */
    std::vector<Nodo*> find() const;


    /**
     * @brief Elimina un contatto dalla rubrica.
     *
     * Chiede all'utente il nome del contatto da eliminare e lo rimuove dalla lista.
     */
    void erase();

    /**
     * @brief Rimuove i contatti duplicati presenti nella lista.
     */
    void unique();

    /**
     * @brief Restituisce il numero di contatti presenti nella lista.
     * @return `size_t` Numero di elementi nella lista.
     */
    constexpr size_t get_size();

    /**
     * @brief Verifica che la lista sia vuota
     * 
     * @return `true` se la lista possiede 0 nodi
     * @return `false` se la lista ha nodi
     */
    constexpr bool empty();

    /**
     * @brief Ordina i contatti nella rubrica in ordine alfabetico.
     */
    void sort();

    /**
     * @brief Modifica i dati di un contatto esistente.
     *
     * Chiede all'utente quale contatto modificare e aggiorna i dati.
     */
    void modifica();

    /**
     * @brief Carica i contatti da un file CSV e li inserisce nella lista.
     */
    void carica_da_file();
};

#endif // LISTA_HPP


