#ifndef LISTA_HPP
#define LISTA_HPP

#pragma once
#include "contatto.hpp"

struct Nodo {
    Contatto contatto;
    Nodo* next;

    Nodo();
};

class List {
private:
    Nodo* head;
    void salva_su_file() const;
    size_t M_size = 0;

public:
    List();
    ~List();

    void push();
    void mostra() const;
    void find() const;
    void erase();
    void unique();
    constexpr size_t get_size();
    void modifica();
    void carica_da_file();
};

#endif