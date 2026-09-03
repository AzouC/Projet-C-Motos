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
    std::string nom;
    std::string prenom;
    int anneeNaissance;
    std::vector<Moto*> mesMotos; ///< Collection de pointeurs vers des motos (Agregation)

public:
    Conducteur(std::string n, std::string p, int a) : nom(n), prenom(p), anneeNaissance(a) {}

    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    
    // Le diagramme UML demande un string en retour pour l'annee
    std::string getAnneeNaissance() const { return std::to_string(anneeNaissance); }

    // Le parametre s'appelle 'newMoto' selon l'UML
    void addMoto(Moto* newMoto) {
        mesMotos.push_back(newMoto);
    }

    // Le parametre s'appelle 'rmMoto' selon l'UML
    void rmMoto(Moto* rmMoto) {
        mesMotos.erase(std::remove(mesMotos.begin(), mesMotos.end(), rmMoto), mesMotos.end());
    }

    std::string toString() const {
        std::string res = "Conducteur: " + prenom + " " + nom + " (Ne en " + getAnneeNaissance() + ")\n";
        res += "  Possede " + std::to_string(mesMotos.size()) + " moto(s):\n";
        for (auto* moto : mesMotos) {
            res += "    - " + moto->toString() + "\n";
        }
        return res;
    }
};
#endif