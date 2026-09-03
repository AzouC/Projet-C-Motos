#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP
#include "Moteur.hpp"

class Electrique : public Moteur {
private:
    float tensionMax;

public:
    Electrique(int p, float tension) : Moteur(p), tensionMax(tension) {}
    
    float getTensionMax() const { return tensionMax; }
    void setTensionMax(float t) { tensionMax = t; }

    std::string toString() const override {
        return "Moteur Electrique (Puissance: " + std::to_string(getPuissance()) + "W, Tension Max: " + std::to_string(tensionMax) + "V)";
    }
};
#endif