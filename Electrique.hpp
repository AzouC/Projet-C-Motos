#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP
#include "Moteur.hpp"

class Electrique : public Moteur {
private:
    float tensionMax;

public:
    Electrique(int p, float tension) : Moteur(p), tensionMax(tension) {}
    
    float getTensionMax() const { return tensionMax; }
    
    // L'UML indique 'puissance' comme parametre, mais cela masque l'attribut 'puissance' herite de Moteur.
    // Utilisation de 'p_puissance' pour satisfaire le flag -Wshadow du compilateur.
    void setTensionMax(float p_puissance) { tensionMax = p_puissance; }

    std::string toString() const override {
        return "Moteur Electrique (Puissance: " + std::to_string(getPuissance()) + "W, Tension Max: " + std::to_string(tensionMax) + "V)";
    }
};
#endif