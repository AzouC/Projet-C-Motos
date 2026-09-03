#ifndef THERMIQUE_HPP
#define THERMIQUE_HPP
#include "Moteur.hpp"

class Thermique : public Moteur {
private:
    float cylindree;

public:
    Thermique(int p, float c) : Moteur(p), cylindree(c) {}
    
    float getCylindree() const { return cylindree; }
    void setCylindree(float c) { cylindree = c; }

    std::string toString() const override {
        return "Moteur Thermique (Puissance: " + std::to_string(getPuissance()) + "W, Cylindree: " + std::to_string(cylindree) + "cc)";
    }
};
#endif