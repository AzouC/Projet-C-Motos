#ifndef MOTEUR_HPP
#define MOTEUR_HPP
#include <string>

/**
 * @brief Classe abstraite representant un moteur.
 */
class Moteur {
private:
    int _puissance; ///< Puissance en Watts

public:
    /**
     * @brief Constructeur de Moteur
     * @param p Puissance du moteur en Watts
     */
    Moteur(int p) : _puissance(p) {}

    /**
     * @brief Destructeur virtuel indispensable pour eviter les fuites memoires lors du polymorphisme.
     */
    virtual ~Moteur() = default;

    int getPuissance() const { return _puissance; }
    void setPuissance(int p) { _puissance = p; }

    /**
     * @brief Methode virtuelle pure pour l'affichage
     * @return std::string Caracteristiques du moteur
     */
    virtual std::string toString() const = 0; 
};
#endif