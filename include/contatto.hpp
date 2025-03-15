#ifndef CONTATTO_HPP
#define CONTATTO_HPP

#pragma once
#include <string>

/**
 * @class Contatto
 * @brief Classe che rappresenta un contatto nella rubrica.
 */
class Contatto {
private:
    std::string nome_completo; ///< Nome completo del contatto
    std::string telefono;      ///< Numero di telefono del contatto
    std::string email;         ///< Indirizzo email del contatto

public:
    /**
     * @brief Costruttore di default della classe Contatto.
     */
    Contatto();

    /**
     * @brief Metodo per inserire i dati del contatto tramite input utente.
     */
    void inserisci();

    /**
     * @brief Metodo per stampare i dati del contatto a schermo.
     */
    void print() const;

    /**
     * @brief Metodo per modificare i dati di un contatto tramite un menu interattivo.
     */
    void modifica();

    /**
     * @brief Restituisce il nome completo del contatto.
     * @return const std::string& Nome del contatto.
     */
    const std::string& get_nome() const;

    /**
     * @brief Restituisce il numero di telefono del contatto.
     * @return const std::string& Numero di telefono.
     */
    const std::string& get_telefono() const;

    /**
     * @brief Restituisce l'indirizzo email del contatto.
     * @return const std::string& Indirizzo email.
     */
    const std::string& get_email() const;

    /**
     * @brief Converte i dati del contatto in formato CSV (stringa separata da virgole).
     * @return std::string Rappresentazione CSV del contatto.
     */
    std::string to_csv() const;

    /**
     * @brief Carica i dati di un contatto da una stringa CSV.
     *
     * Il metodo estrae le informazioni dalla stringa e le assegna ai membri della classe.
     * @param line Stringa contenente i dati del contatto in formato CSV.
     */
    void from_csv(const std::string& line);
};

#endif // CONTATTO_HPP
