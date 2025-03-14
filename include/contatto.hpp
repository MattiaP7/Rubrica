#ifndef CONTATTO_HPP
#define CONTATTO_HPP


#pragma once
#include <string>

class Contatto {
private:
    std::string nome_completo;
    std::string telefono;
    std::string email;

public:
    Contatto();

    void inserisci();

    void print() const;

    void modifica();

    const std::string& get_nome() const;
    const std::string& get_telefono() const;
    const std::string& get_email() const;

    std::string to_csv() const;
    void from_csv(const std::string& line);
};


#endif