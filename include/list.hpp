#ifndef LISTA_HPP
#define LISTA_HPP

#pragma once
#include "contatto.hpp"

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
    Nodo* head; ///< Puntatore alla testa della lista
    size_t M_size = 0; ///< Numero di elementi presenti nella lista

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
     * @brief Inserisce un nuovo contatto nella lista in ordine alfabetico.
     *
     * Se il contatto esiste già, non viene inserito.
     */
    void push();

    /**
     * @brief Mostra tutti i contatti presenti nella rubrica.
     */
    void mostra() const;

    /**
     * @brief Cerca un contatto nella rubrica per nome.
     *
     * Se il contatto viene trovato, i suoi dati vengono stampati a schermo.
     */
    void find() const;

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
     * @return size_t Numero di elementi nella lista.
     */
    constexpr size_t get_size();

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
