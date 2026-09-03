#ifndef CONDUCTEUR_HPP
#define CONDUCTEUR_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "Moto.hpp"

/**
 * @brief Classe représentant un Conducteur (Agrégation avec Moto)
 */
class Conducteur {
private:
    std::string nom;
    std::string prenom;
    int anneeNaissance;
    std::vector<Moto*> mesMotos; ///< Collection de pointeurs vers des motos (Agrégation)

public:
    Conducteur(std::string n, std::string p, int a) : nom(n), prenom(p), anneeNaissance(a) {}

    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    
    // Le diagramme UML demande un string en retour pour l'année
    std::string getAnneeNaissance() const { return std::to_string(anneeNaissance); }

    void addMoto(Moto* newMoto) {
        mesMotos.push_back(newMoto);
    }

    void rmMoto(Moto* rmMoto) {
        // Supprime la moto de la liste sans détruire l'objet Moto lui-même (Agrégation)
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