#ifndef MOTO_HPP
#define MOTO_HPP
#include <string>
#include "Moteur.hpp"

/**
 * @brief Classe representant une Moto (Composition avec Moteur)
 */
class Moto {
private:
    int poids; 
    std::string couleur;
    std::string nom;
    Moteur* moteur; ///< Pointeur vers le moteur (Composition)

public:
    // Ajout du prefixe 'p_' pour eviter le warning -Wshadow avec les attributs
    Moto(Moteur* p_moteur, std::string p_couleur) : poids(0), couleur(p_couleur), nom("Inconnu"), moteur(p_moteur) {}

    /**
     * @brief Destructeur de la Moto. 
     * Gere la destruction du moteur (relation de composition).
     */
    ~Moto() {
        delete moteur; 
    }

    int getPoids() const { return poids; }
    
    // Ajout du prefixe 'p_' pour eviter le warning -Wshadow
    void setPoids(int p_poids) { poids = p_poids; }
    
    std::string getCouleur() const { return couleur; }
    
    Moteur* getMoteur() const { return moteur; }

    /**
     * @brief Calcule l'acceleration theorique a 50 km/h
     * Formule : a = P / (m * v)
     * @return float L'acceleration en m/s^2
     */
    float getAcceleration() const {
        if (poids == 0) return 0;
        // 50 km/h = 50 / 3.6 m/s
        float vitesse_ms = 50.0f / 3.6f; 
        return static_cast<float>(moteur->getPuissance()) / (static_cast<float>(poids) * vitesse_ms);
    }

    std::string toString() const {
        return "Moto " + couleur + " (" + std::to_string(poids) + "kg)\n    Accel a 50km/h: " 
               + std::to_string(getAcceleration()) + " m/s2\n    -> " + moteur->toString();
    }
};
#endif