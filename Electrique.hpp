#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP
#include "Moteur.hpp"

class Electrique : public Moteur {
private:
    float _tensionMax;

public:
    Electrique(int p, float tension) : Moteur(p), _tensionMax(tension) {}
    
    float getTensionMax() const { return _tensionMax; }
    
    void setTensionMax(float p_puissance) { _tensionMax = p_puissance; }

    std::string toString() const override {
        return "Moteur Electrique (Puissance: " + std::to_string(getPuissance()) + "W, Tension Max: " + std::to_string(_tensionMax) + "V)";
    }
};
#endif