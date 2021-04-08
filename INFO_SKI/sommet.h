#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>

class sommet
{
private:
    int m_num;
    std:: string m_nom;
    int m_altitude;
public:
    std::vector< sommet> m_voisins;
    sommet();
    sommet(int _num, std:: string _nom, int _altitude);
    ~sommet();
    int getNum() const;
    /*accesseur : pour la liste des successeurs
    std::vector<sommet>& getSuccesseurs();
    // pour ajouter un successeur � la liste
    void ajouterSucc ( sommet*s);
    // m�thode d'affichage
    void afficher() const;*/

};


#endif // SOMMET_H_INCLUDED
