#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <queue>
#include <stack>
#include <utility>
#include <limits.h>
#include <stdio.h>
#include <set>




class Sommet
{
private :
    int m_num;
    //std:: vector < std :: vector<std:: pair<Sommet*,int> > > distance;

public :
    ///chaque sommet possède la liste de ses successeurs (un vecteur de pointeurs sur Sommet)
    std::vector< Sommet*> m_successeurs;


    /*constructeur*/
    Sommet(int num):m_num{num} {};
    /*accesseurs*/
    int getNum()const
    {
        return m_num;
    }
    ///accesseur : pour la liste des successeurs
    std::vector<Sommet*>& getSuccesseurs()
    {
        return m_successeurs;
    }
    /* pour ajouter un successeur à la liste*/
    void ajouterSucc( Sommet*s)
    {
        m_successeurs.push_back(s);
    }
    /* méthode d'affichage*/
    void afficher() const
    {
        std::cout<<"     sommet "<<m_num<<" : ";
        for (auto s : m_successeurs)
            std::cout<<s->getNum()<<" ";
    }

};

class arc
{
    std::string type;
};
class Graphe
{
private :
    ///liste des sommets (vecteur de pointeurs sur Sommet)

    int m_orientation;

public :
    std::vector<Sommet*> m_sommets;
    std:: vector<int> vector_poids;
    unsigned int ordre;

    /* La construction du réseau peut se faire à partir d'un fichier
     dont le nom est passé en paramètre
    Le fichier contient : orientation (0 ou 1), ordre, taille, liste des arcs */
    Graphe(std::string nomFichier)
    {
        std::ifstream ifs{nomFichier};
        if (!ifs)
            throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

        ifs >> m_orientation;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture orientation du graphe");

        ifs >> ordre;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture ordre du graphe");

        int taille;
        ifs >> taille;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture taille du graphe");



        for (unsigned int i=0; i<ordre; ++i)
            m_sommets.push_back( new Sommet{i} );
        int num1,num2,poids,arc_arrete;
        num1=0;
        unsigned int k=0;


        std:: vector < std:: pair<Sommet*,int> > distance_1_ARC; // declaration d'un Vecteur de pair

        for (int i=0; i<taille; ++i)
        {
                ifs>>num1>>num2>>poids>>arc_arrete;
                if ( ifs.fail() )
                    throw std::runtime_error("Probleme lecture arc");

                m_sommets[num1]->ajouterSucc(m_sommets[num2]);
                if(arc_arrete==0)   // si c'est arc orienté dans les 2 sens alors on ajoute les successeurs dans les 2 sens
                    m_sommets[num2]->ajouterSucc(m_sommets[num1]);

                 vector_poids.push_back(poids);


            ///si le graphe n'est pas orienté
            ///si num2 est successeur de num1, num1 est successeur de num2
            //if(!m_orientation)
            //m_sommets[num2]->ajouterSucc(m_sommets[num1]);



        }
    }
    /*destructeur*/
    ~Graphe()
    {
        for (auto s : m_sommets)
            delete s;
    }
    /*méthode d'affichage*/
    void afficher() const
    {
        std::cout<<std::endl<<"graphe ";
        if(m_orientation)
            std::cout<<"oriente"<<std::endl<<"  ";
        else
            std::cout<<"non oriente"<<std::endl<<"  ";
        std::cout<<"ordre = "<<m_sommets.size()<<std::endl<<"  ";
        std::cout<<"listes d'adjacence :"<<std::endl;
        for (auto s : m_sommets)
        {
            s->afficher();
            std::cout<<std::endl;
        }
    }



    void dijkstra(int numero)
    {
        /// VECTOR DE VECTOR DE PAIR QUI PERMET D'AVOIR LA DISTANCE DE CHAQUE ARC
        std:: vector < std :: vector<std:: pair<Sommet*,int> > > distance;


        unsigned int k=0;
        for(unsigned int j=0; j<ordre; j++) // Pour parcourir tous les sommets
        {
            std:: vector < std:: pair<Sommet*,int> > distance_1_ARC; // declaration d'un Vecteur de pair

            for(unsigned int i=0; i<m_sommets[j]->getSuccesseurs().size(); i++) // pour parcourir tous les successeurs
            {

                distance_1_ARC.push_back(std::make_pair(m_sommets[j]->getSuccesseurs()[i],vector_poids[k]));
                k++;    // Pour chaque sommet defini par j on push back dans le pair un de ses successeurs et le poids de l'arc
            }
            distance.push_back(distance_1_ARC); // enfin on push back les pairs qui contiennent le successeur du sommet defini
                                                // par j et le poids de l'arc que forme le sommet de j et son successeur
        }                                       // la premiere case de distance contient du coup ts les pairs liés au premier
                                                // sommet avec le poids de leur arc, la 2eme case meme chose pour le 2eme sommet...
                                                // exemple pour trouver le poids:
                                                //std:: cout << "" <<distance[1][0].second<<std::endl;
        /// PHASE D'INITIALISATION ON MARQUE TOUS LES SOMMETS NON PARCOURUS ET LES DISTANCES A +∞/ INT_MAX
        std::vector< Sommet*> sommetsDecouverts;   //

        std:: vector < std :: vector<std:: pair<Sommet*,int> > > distance_init;
        for(unsigned int j=0; j<ordre; j++) // Pour parcourir tous les sommets
        {
            std:: vector < std:: pair<Sommet*,int> > distance_init2; // declaration d'un Vecteur de pair

            for(unsigned int i=0; i<m_sommets[j]->getSuccesseurs().size(); i++) // pour parcourir tous les successeurs
            {

                distance_init2.push_back(std::make_pair(m_sommets[j]->getSuccesseurs()[i],INT_MAX));

            }
            distance_init.push_back(distance_init2);
        }
        std:: cout << "" <<distance[0][1].second<<std::endl;
        std:: cout << "" <<distance_init[6][0].second<<std::endl;
        //std:: cout<< m_sommets[6]->getSuccesseurs()[4]->getNum();



        std::vector< bool> Sommet_marq;
        for(unsigned int i=0; i<ordre; i++)
        {
            Sommet_marq.push_back(false);
        }




        sommetsDecouverts.push_back(m_sommets[numero]);
        int chemin=0;
        int temp=0;

        while(sommetsDecouverts.size()<ordre)
        {

            Sommet_marq[m_sommets[numero]->getNum()]=true;
            std:: vector<int>TRI;

            /// SI LE SUCCESSEUR N'EST PAS VISITE
            for(unsigned int i=0; i<m_sommets[numero]->getSuccesseurs().size(); i++)
            {

                unsigned int min= distance_init[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second;
                //std::cout<<distance[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second + chemin<<std:: endl;
                if((Sommet_marq[m_sommets[numero]->getSuccesseurs()[i]->getNum()]==false)&&(distance[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second + chemin<distance_init[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second))
                {
                    min= distance[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second+chemin;


                }

                TRI.push_back(min);
            }
            /*for(unsigned int m=0;m<TRI.size();m++)
            {
            std::cout<<TRI[m]<<std:: endl;
            }*/

            // TRI PAR BULLE
            for(unsigned int i=0; i<300; i++)
            {
                for(unsigned int j=0; j<TRI.size(); j++)
                {
                    if(TRI[j]<TRI[j+1])
                    {

                        temp= TRI[j];
                        TRI[j]=TRI[j+1];
                        TRI[j+1]=temp;
                    }
                }
            }

            chemin=chemin+ TRI[0];
            for(unsigned int i=0; i<m_sommets[numero]->getSuccesseurs().size(); i++)
            {

                if((TRI[0])== (distance[numero][m_sommets[numero]->getSuccesseurs()[i]->getNum()].second + chemin))
                {

                    sommetsDecouverts.push_back(m_sommets[m_sommets[numero]->getSuccesseurs()[i]->getNum()]);
                    numero=m_sommets[numero]->getSuccesseurs()[i]->getNum();
                }

            }
        }








        for(unsigned int i=0; i<sommetsDecouverts.size(); i++)
        {
            std::cout<<sommetsDecouverts[i]->getNum() << " <---- ";

        }


    }

};



int main()
{

    Graphe g{"graphe2_TP3.txt"};

    ///appel de la méthode pour afficher le graphe

    ///saisie du numéro du sommet initial pour lancer un BFS
    int numero=0;
    std::cout<<"veuillez choisir un numero de sommet ou commencer le parcours"<<std::endl;
    std::cin>>numero;
    std::cout<<std::endl<<"numero du sommet initial : "<<numero;

    /// afficher le graphe
    g.afficher();
    std::cout<<"Parcours dijkstra:   "<<std::endl;
    g.dijkstra(numero);

    Sommet Sommet_init(numero);
    return 0;

}
