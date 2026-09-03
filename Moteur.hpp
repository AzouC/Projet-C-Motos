#ifndef MOTEUR_HPP
#define MOTEUR_HPP
#include <string>

/**
 * @brief Classe abstraite representant un moteur.
 */
class Moteur {
private: // Modifie en 'private' pour respecter le '-' du diagramme UML
    int puissance; ///< Puissance en Watts

public:
    /**
     * @brief Constructeur de Moteur
     * @param p Puissance du moteur en Watts
     */
    Moteur(int p) : puissance(p) {}

    /**
     * @brief Destructeur virtuel indispensable pour eviter les fuites memoires lors du polymorphisme.
     */
    virtual ~Moteur() = default;

    int getPuissance() const { return puissance; }
    void setPuissance(int p) { puissance = p; }

    /**
     * @brief Methode virtuelle pure pour l'affichage
     * @return std::string Caracteristiques du moteur
     */
    virtual std::string toString() const = 0; 
};
#endif