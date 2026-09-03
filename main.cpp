#include <iostream>
#include "Conducteur.hpp"
#include "Electrique.hpp"
#include "Thermique.hpp"

int main() {
    std::cout << "--- 1. Creation 1 conducteur et 2 motos ---\n";
    Conducteur daniel("Dupont", "Daniel", 2008);

    // Création des moteurs (35kW = ~47ch pour le permis A2 par exemple)
    Moteur* motTherm = new Thermique(35000, 500.0f); 
    Moto* moto1 = new Moto(motTherm, "Rouge", "Honda CB500", 190);

    Moteur* motElec = new Electrique(40000, 400.0f);
    Moto* moto2 = new Moto(motElec, "Noir", "Zero SR", 220);

    std::cout << "\n--- 2. Attribution des motos au conducteur ---\n";
    daniel.addMoto(moto1);
    daniel.addMoto(moto2);

    std::cout << "\n--- 3. Affichage du conducteur ---\n";
    std::cout << daniel.toString() << "\n";

    std::cout << "\n--- 4. Creation 2 nouveaux conducteurs et 1 nouvelle moto ---\n";
    Conducteur alex("Martin", "Alex", 2005);
    Conducteur sam("Lefebvre", "Sam", 2004);

    Moteur* motTherm2 = new Thermique(70000, 900.0f);
    Moto* moto3 = new Moto(motTherm2, "Bleu", "Yamaha MT-09", 189);

    std::cout << "\n--- 5. Repartition (1 moto par conducteur) et affichage ---\n";
    daniel.rmMoto(moto2); // On enlève la moto électrique à Daniel
    
    alex.addMoto(moto2);  // On la donne à Alex
    sam.addMoto(moto3);   // On donne la nouvelle moto à Sam

    std::cout << daniel.toString() << "\n";
    std::cout << alex.toString() << "\n";
    std::cout << sam.toString() << "\n";

    // --- Gestion de la mémoire ---
    // Les objets Moto ont été alloués avec 'new', il faut les détruire manuellement.
    // Les moteurs à l'intérieur seront détruits automatiquement grâce au destructeur de Moto (~Moto).
    delete moto1;
    delete moto2;
    delete moto3;

    return 0;
}