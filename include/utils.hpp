/**
 * @file utils.hpp
 * @brief questo file racchiude funzioni wrapper, come verifica della email,
 * telefono.
 */


#ifndef UTILS_HPP
#define UTILS_HPP

#pragma once
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Funzione ausiliare per controllare se una stringa (email) sia una valida email. Per "valida email" intendo una stringa con `@` e seguita da un dominio come `gmail.com`.
 * 
 * @param email stringa da controllare
 * @return true - se valida
 * @return false - se invalida
 */
bool isEmail(const std::string& email);


#endif