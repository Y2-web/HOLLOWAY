#include "graphe.h"

unsigned int graphe:: getOrdre() const
{
    return m_ordre;
}

unsigned int graphe:: getTaille() const
{
    return m_taille;
}

std::vector<sommet> graphe :: getSommets() const
{
    return m_sommets;
}

std::vector<arcs> graphe :: getArcs() const
{
    return m_arcs;
}

std:: vector< std:: vector< sommet>> graphe :: getListeVoisins() const
{
    return liste_voisins;
}


graphe:: graphe(std:: string nomFichier)
{

    std:: ifstream fichier{nomFichier}; /// ou std::ifstream fichier(nomFichier.c_str())
    if(fichier)
    {

     fichier >> m_ordre;
     if ( fichier.fail() )
            throw std::runtime_error("Probleme lecture ordre du graphe");
     for(unsigned int i=1;i<=m_ordre;i++)
     {
         int num, altitude;
         std:: string nom;
         fichier >> num >> nom >> altitude;
         if ( fichier.fail() )
            throw std::runtime_error("Probleme lecture sommet"+ i);
         sommet s1(num, nom, altitude);
         m_sommets.push_back(s1);
     }
     fichier >> m_taille;
     ///std:: cout<<m_taille;   ----> donne bien 95


     for(unsigned int k=1;k<=m_ordre;k++)
        liste_voisins.push_back(std:: vector<sommet>());

     for(unsigned int j=1;j<=m_taille;j++)
     {
         int num, pointD, pointA,tempsA,tempsB;
         double tempsReel;
         std:: string nom, type;
         fichier >> num >> nom >> type >> pointD >> pointA >> tempsA >> tempsB;

         if((type=="V")||(type=="B")||(type=="R")||(type=="N")||(type=="KL")||(type=="SURF"))
         {
             tempsReel= (tempsA*(m_sommets[pointD-1].getAltitude()-m_sommets[pointA-1].getAltitude()))/100;
         }
         else if(type=="BUS")
         {
             tempsReel= tempsA;
         }
         else if((type=="TPH")||(type=="TC")||(type=="TSD")||(type=="TS")||(type=="TK"))
         {
             tempsReel= tempsA +(tempsB*(m_sommets[pointA-1].getAltitude()-m_sommets[pointD-1].getAltitude()))/100;
         }

         liste_voisins[pointD-1].push_back(m_sommets[pointA-1]);
         arcs A(num, nom, type, pointD, pointA, tempsReel);
         m_arcs.push_back(A);
     }

    /// exemple d'un voisin de 3 ---> std:: cout<<liste_voisins[2][2].getNum()<<std::endl;
    //std::cout<<m_arcs[26].getTempsR();


    }
    else
    {
        std::cout<<"ERREUR"<<std::endl; /// ou throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    }

}
