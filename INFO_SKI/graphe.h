#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "sommet.h"
#include "arcs.h"
#include <stdio.h>
#include <utility>
#include <fstream>
#include <limits.h>
#include <list>

class graphe
{
private:
    unsigned int m_ordre;
    unsigned int m_taille;
    std::vector<sommet> m_sommets;
    std::vector<arcs> m_arcs;
    std:: vector< std:: vector< sommet>> liste_voisins; /// La case 0 du double vecteur représente tous les voisins de 1.
public:

    graphe(std:: string nomFichier);
    unsigned int getOrdre() const;
    unsigned int getTaille() const;
    std::vector<sommet> getSommets() const;
    std::vector<arcs> getArcs() const;
    std:: vector< std:: vector< sommet>> getListeVoisins() const;



};

#endif // GRAPHE_H_INCLUDED
