#ifndef CONTATTO_HPP
#define CONTATTO_HPP


#pragma once
#include <string>

/**
 * @brief Classe `Contatto`, rappresenta il contatto nella rubrica
 *
 */
class Contatto {
private:
    std::string nome_completo;
    std::string telefono;
    std::string email;

public:
    /// @brief costruttore di default
    Contatto();

    /// @brief metodo per inserire i valori del contatto
    void inserisci();

    /// @brief metodo per stampare i dati di un contatto
    void print() const;

    /// @brief metodo che permette la modifica dei dati di un contatto tramite un menu di scelta
    void modifica();

    // tutti i getter, servono a ritornare i dati effettivi del contatto

    const std::string& get_nome() const;
    const std::string& get_telefono() const;
    const std::string& get_email() const;

    /**
     * @brief metodo che ritorna una stirnga costituita dai dati del contatto
     *
     * @return std::string
     */
    std::string to_csv() const;

    /**
     * @brief metodo che carica i dati da un file CSV e gli inserisci in una struttura dati
     * 1 - Legge il file `contatti.csv`
     * 2 - Estraee i dati
     * 3 - Crea oggetti "Contatto" e gli aggiunge alla struttura dati
     *
     * @param line
     */
    void from_csv(const std::string& line);
};


#endif