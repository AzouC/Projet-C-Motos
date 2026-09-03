#ifndef MOTO_HPP
#define MOTO_HPP
#include <string>
#include "Moteur.hpp"

/**
 * @brief Classe representant une Moto (Composition avec Moteur)
 */
class Moto {
private:
    int _poids; 
    std::string _couleur;
    std::string _nom;
    Moteur* _moteur; ///< Pointeur vers le moteur (Composition)

public:
    Moto(Moteur* p_moteur, std::string p_couleur) 
        : _poids(0), _couleur(p_couleur), _nom("Inconnu"), _moteur(p_moteur) {}

    /**
     * @brief Destructeur de la Moto. 
     * Gere la destruction du moteur (relation de composition).
     */
    ~Moto() {
        delete _moteur; 
    }

    int getPoids() const { return _poids; }
    
    void setPoids(int p_poids) { _poids = p_poids; }
    
    std::string getCouleur() const { return _couleur; }
    
    Moteur* getMoteur() const { return _moteur; }

    /**
     * @brief Calcule l'acceleration theorique a 50 km/h
     * Formule : a = P / (m * v)
     * @return float L'acceleration en m/s^2
     */
    float getAcceleration() const {
        if (_poids == 0) return 0;
        // 50 km/h = 50 / 3.6 m/s
        float vitesse_ms = 50.0f / 3.6f; 
        return static_cast<float>(_moteur->getPuissance()) / (static_cast<float>(_poids) * vitesse_ms);
    }

    std::string toString() const {
        return "Moto " + _couleur + " (" + std::to_string(_poids) + "kg)\n    Accel a 50km/h: " 
               + std::to_string(getAcceleration()) + " m/s2\n    -> " + _moteur->toString();
    }
};
#endif