#ifndef RUBRICA_HPP
#define RUBRICA_HPP

#include "list.hpp"

/**
 * @class Rubrica
 * @brief Classe che gestisce l'interfaccia utente della rubrica.
 */
class Rubrica {
private:
    List lista; ///< Lista che contiene i contatti della rubrica
    
public:
    /**
     * @brief Avvia l'applicazione della rubrica.
     *
     * Presenta un menu all'utente per eseguire operazioni sulla rubrica.
     */
    void Applicazione();
};

#endif // RUBRICA_HPP
