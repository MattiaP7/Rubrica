#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>


/**
 * @brief Calcola la larghezza delle colonne in base ai dati passati.
 *
 * @param dati Vettore bidimensionale contenente i dati(in stringa) della tabella.
 * @return std::vector<int> Vettore contenente la larghezza di ciascuna colonna.
 */
std::vector<int> calcolaLarghezze(const std::vector<std::vector<std::string>>& dati);

/**
 * @brief Centra un testo in una larghezza specificata.
 *
 * @param testo Il testo da centrare.
 * @param larghezza La larghezza totale della cella.
 * @return std::string Testo centrato con spazi ai lati.
 */
std::string centraTesto(const std::string& testo, int larghezza);


/**
 * @brief Funzione utility che data una stringa la trasforma in lowercase, utilizzata per la funzione List::find()
 * 
 * @param str Stringa da modificare
 * @return std::string  Stringa stessa ma in lower case
 */
std::string to_lower(const std::string& str);

/**
 * @brief Stampa una riga separatrice per la tabella.
 *
 * @param larghezze Vettore contenente le larghezze delle colonne.
 *
*/
void stampaSeparatore(const std::vector<int>& larghezze);


/**
 * @brief Stampa una tabella con i dati forniti.
 *
 * @tparam Args Tipi dei dati (deve essere un vettore bidimensionale definito come std::vector<std::string>).
 * @param righe Righe della tabella da stampare.
 */
template <typename... Args>
void stampaTabella(Args... righe) {
    std::vector<std::vector<std::string>> dati = { righe... };

    if (dati.empty())
        return;

    std::vector<int> larghezze = calcolaLarghezze(dati);

    stampaSeparatore(larghezze);

    for (size_t r = 0; r < dati.size(); r++) {
        for (size_t i = 0; i < dati[r].size(); i++) {
            std::cout << "| " << std::setw(larghezze[i]) << std::left
                << centraTesto(dati[r][i], larghezze[i]) << " ";
        }
        std::cout << "|\n";

        if (r == 0) { // Dopo l'intestazione, stampa il separatore
            stampaSeparatore(larghezze);
        }
    }

    stampaSeparatore(larghezze);
}


#endif // UTILS_HPP
