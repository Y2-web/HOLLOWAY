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
public:
    std::vector<sommet> m_sommets;
    std::vector<arcs> m_arcs;
    graphe(std:: string nomFichier);



};

#endif // GRAPHE_H_INCLUDED
