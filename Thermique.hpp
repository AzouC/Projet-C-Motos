#ifndef THERMIQUE_HPP
#define THERMIQUE_HPP
#include "Moteur.hpp"

class Thermique : public Moteur {
private:
    float _cylindree;

public:
    Thermique(int p, float c) : Moteur(p), _cylindree(c) {}
    
    float getCylindree() const { return _cylindree; }
    
    void setCylindree(float newCylindree) { _cylindree = newCylindree; }

    std::string toString() const override {
        return "Moteur Thermique (Puissance: " + std::to_string(getPuissance()) + "W, Cylindree: " + std::to_string(_cylindree) + "cc)";
    }
};
#endif