#include "../include/utils.hpp"
#include <iomanip>
#include <iostream>


std::vector<int> calcolaLarghezze(const std::vector<std::vector<std::string>>& dati) {
    size_t colonne = dati[0].size();
    std::vector<int> larghezze(colonne, 0);

    for (const auto& riga : dati) {
        for (size_t i = 0; i < colonne; i++) {
            larghezze[i] = std::max(larghezze[i], static_cast<int>(riga[i].size()));
        }
    }
    return larghezze;
}

std::string centraTesto(const std::string& testo, int larghezza) {
    int spazioSinistra = (larghezza - testo.size()) / 2;
    int spazioDestra = larghezza - testo.size() - spazioSinistra;
    return std::string(spazioSinistra, ' ') + testo + std::string(spazioDestra, ' ');
}

void stampaSeparatore(const std::vector<int>& larghezze) {
    for (int w : larghezze) {
        std::cout << "+-" << std::string(w, '-') << "-";
    }
    std::cout << "+\n";
}
