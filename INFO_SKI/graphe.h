#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include "sommet.h"
#include "arcs.h"
#include <stdio.h>
#include <utility>
#include <fstream>

class graphe
{
private:
    unsigned int m_ordre;
    unsigned int m_taille;
    std::vector<sommet> m_sommets;
    std::vector<arcs> m_arcs;
public:

    graphe(std:: string nomFichier);
    unsigned int getOrdre() const;
    unsigned int getTaille() const;
    std::vector<sommet> getSommets() const;
    std::vector<arcs> getArcs() const;



};

#endif // GRAPHE_H_INCLUDED
