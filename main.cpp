#include <iostream>
#include "Conducteur.hpp"
#include "Electrique.hpp"
#include "Thermique.hpp"

int main() {
    std::cout << "--- 1. Creation 1 conducteur et 2 motos ---\n";
    Conducteur daniel("Dupont", "Daniel", 2008);

    Moteur* motTherm = new Thermique(35000, 500.0f); 
    // Utilisation du constructeur strict UML (moteur, couleur)
    Moto* moto1 = new Moto(motTherm, "Rouge");
    // Le poids est defini via le setter comme prevu dans le diagramme
    moto1->setPoids(190); 

    Moteur* motElec = new Electrique(40000, 400.0f);
    Moto* moto2 = new Moto(motElec, "Noir");
    moto2->setPoids(220);

    std::cout << "\n--- 2. Attribution des motos au conducteur ---\n";
    daniel.addMoto(moto1);
    daniel.addMoto(moto2);

    std::cout << "\n--- 3. Affichage du conducteur ---\n";
    std::cout << daniel.toString() << "\n";

    std::cout << "\n--- 4. Creation 2 nouveaux conducteurs et 1 nouvelle moto ---\n";
    Conducteur alex("Martin", "Alex", 2005);
    Conducteur sam("Lefebvre", "Sam", 2004);

    Moteur* motTherm2 = new Thermique(70000, 900.0f);
    Moto* moto3 = new Moto(motTherm2, "Bleu");
    moto3->setPoids(189);

    std::cout << "\n--- 5. Repartition (1 moto par conducteur) et affichage ---\n";
    daniel.rmMoto(moto2); // On enleve la moto electrique a Daniel
    
    alex.addMoto(moto2);  // On la donne a Alex
    sam.addMoto(moto3);   // On donne la nouvelle moto a Sam

    std::cout << daniel.toString() << "\n";
    std::cout << alex.toString() << "\n";
    std::cout << sam.toString() << "\n";

    // --- Gestion de la memoire ---
    // Les objets Moto ont ete alloues avec 'new', il faut les detruire manuellement.
    // Les moteurs a l'interieur seront detruits automatiquement grace au destructeur de Moto (~Moto).
    delete moto1;
    delete moto2;
    delete moto3;

    return 0;
}