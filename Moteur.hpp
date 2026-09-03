#ifndef MOTEUR_HPP
#define MOTEUR_HPP
#include <string>

/**
 * @brief Classe abstraite représentant un moteur.
 */
class Moteur {
protected:
    int puissance; ///< Puissance en Watts

public:
    /**
     * @brief Constructeur de Moteur
     * @param p Puissance du moteur en Watts
     */
    Moteur(int p) : puissance(p) {}

    /**
     * @brief Destructeur virtuel indispensable pour éviter les fuites mémoires lors du polymorphisme.
     */
    virtual ~Moteur() = default;

    int getPuissance() const { return puissance; }
    void setPuissance(int p) { puissance = p; }

    /**
     * @brief Méthode virtuelle pure pour l'affichage
     * @return std::string Caractéristiques du moteur
     */
    virtual std::string toString() const = 0; 
};
#endif