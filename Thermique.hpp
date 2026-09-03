#ifndef THERMIQUE_HPP
#define THERMIQUE_HPP
#include "Moteur.hpp"

class Thermique : public Moteur {
private:
    float cylindree;

public:
    Thermique(int p, float c) : Moteur(p), cylindree(c) {}
    
    float getCylindree() const { return cylindree; }
    
    // Le parametre s'appelle 'newCylindree' pour correspondre parfaitement a l'UML
    void setCylindree(float newCylindree) { cylindree = newCylindree; }

    std::string toString() const override {
        return "Moteur Thermique (Puissance: " + std::to_string(getPuissance()) + "W, Cylindree: " + std::to_string(cylindree) + "cc)";
    }
};
#endif