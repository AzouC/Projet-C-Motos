#ifndef MOTO_HPP
#define MOTO_HPP
#include <string>
#include "Moteur.hpp"

/**
 * @brief Classe représentant une Moto (Composition avec Moteur)
 */
class Moto {
private:
    int poids; 
    std::string couleur;
    std::string nom;
    Moteur* moteur; ///< Pointeur vers le moteur (Composition)

public:
    Moto(Moteur* m, std::string c, std::string n, int p) : moteur(m), couleur(c), nom(n), poids(p) {}

    /**
     * @brief Destructeur de la Moto. 
     * Gère la destruction du moteur (relation de composition).
     */
    ~Moto() {
        delete moteur; 
    }

    int getPoids() const { return poids; }
    void setPoids(int p) { poids = p; }
    
    std::string getCouleur() const { return couleur; }
    std::string getNom() const { return nom; }
    Moteur* getMoteur() const { return moteur; }

    /**
     * @brief Calcule l'accélération théorique à 50 km/h
     * Formule : a = P / (m * v)
     * @return float L'accélération en m/s^2
     */
    float getAcceleration() const {
        if (poids == 0) return 0;
        // 50 km/h = 50 / 3.6 m/s
        float vitesse_ms = 50.0f / 3.6f; 
        return moteur->getPuissance() / (poids * vitesse_ms);
    }

    std::string toString() const {
        return "Moto " + nom + " (" + couleur + ", " + std::to_string(poids) + "kg)\n    Accel a 50km/h: " 
               + std::to_string(getAcceleration()) + " m/s2\n    -> " + moteur->toString();
    }
};
#endif