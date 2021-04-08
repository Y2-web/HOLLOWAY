#include "sommet.h"
#include <iostream>

sommet:: sommet()
{

}

sommet:: sommet(int _num, std:: string _nom, int _altitude)
{
    m_num= _num;
    m_nom = _nom;
    m_altitude= _altitude;
}

sommet::~sommet()
{

}

int sommet:: getNum() const
{
    return m_num;
}

///accesseur : pour la liste des successeurs
/*std::vector<sommet*>& sommet:: getSuccesseurs()
{
    return m_successeurs;
}*/

/* pour ajouter un successeur à la liste*/
/*void sommet:: ajouterSucc( sommet*s)
{
    m_successeurs.push_back(s);
}*/

/* méthode d'affichage*/
/*void sommet:: afficher() const
{
    std::cout<<"     sommet "<<m_num<<" : ";
    for (auto s : m_successeurs)
        std::cout<<s->getNum()<<" ";
}*/
