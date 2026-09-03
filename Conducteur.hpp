#ifndef CONDUCTEUR_HPP
#define CONDUCTEUR_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "Moto.hpp"

/**
 * @brief Classe representant un Conducteur (Agregation avec Moto)
 */
class Conducteur {
private:
    std::string _nom;
    std::string _prenom;
    int _anneeNaissance;
    std::vector<Moto*> _mesMotos; ///< Collection de pointeurs vers des motos (Agregation)

public:
    Conducteur(std::string n, std::string p, int a) 
        : _nom(n), _prenom(p), _anneeNaissance(a) {}

    std::string getNom() const { return _nom; }
    std::string getPrenom() const { return _prenom; }
    
    std::string getAnneeNaissance() const { return std::to_string(_anneeNaissance); }

    void addMoto(Moto* newMoto) {
        _mesMotos.push_back(newMoto);
    }

    void rmMoto(Moto* rmMoto) {
        _mesMotos.erase(std::remove(_mesMotos.begin(), _mesMotos.end(), rmMoto), _mesMotos.end());
    }

    std::string toString() const {
        std::string res = "Conducteur: " + _prenom + " " + _nom + " (Ne en " + getAnneeNaissance() + ")\n";
        res += "  Possede " + std::to_string(_mesMotos.size()) + " moto(s):\n";
        for (auto* moto : _mesMotos) {
            res += "    - " + moto->toString() + "\n";
        }
        return res;
    }
};
#endif