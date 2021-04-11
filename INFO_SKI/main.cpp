#include "graphe.h"
/// PROTOTYPES
void Retour13(graphe g);
void Retour12(graphe g);
void Retour11(graphe g);
void Menu1(graphe g);

///************************************** ALGORITHME DE DIJKSTRA ***************************************************///
void dijkstra(graphe g, int sommetD)
{
    /// DECLARATIONS
    std::vector<bool> sommetMarq;
    std::vector<bool> ArcsMarq;
    std:: vector<double> minDist; /// DISTANCE DU SOMMET DE DEPART AU SOMMET i
    std::vector<arcs> ArcsParcourus;
    int distanceTot=0;

    /// INITIALISATION

    /// TOUS LES SOMMETS NON MARQUES /// TOUS LES DISTANCES AU SOMMET DE DEPART A L'INFINI
    for(unsigned int i=0; i<g.getOrdre(); i++)
    {
        sommetMarq.push_back(false);  /// si non marqué -----> 0 si marqué -----> 1
        minDist.push_back(INT_MAX);
    }

    for(unsigned int i=0; i<g.getTaille(); i++)
    {
        ArcsMarq.push_back(false);
    }

    minDist[sommetD-1]=0;
    sommetMarq[sommetD-1]=true;

    //int min= INT_MAX, source= 0;

    /// DEBUT DE L'ALGORITHME

    while(ArcsParcourus.size()<g.getTaille())
    {
        std::list <double> TRI;

        for(unsigned int i=0; i<g.getTaille(); i++)
        {
            if(g.getArcs()[i].getPointD()== sommetD)     // SI L'ARC PART DU SOMMET DE DEPARt
            {
                if(sommetMarq[g.getArcs()[i].getPointA()-1]== false)                  // SI L'ARC N'EST PAS MARQUE
                {
                    ArcsParcourus.push_back(g.getArcs()[i]);

                    if(g.getArcs()[i].getTempsR() + distanceTot <minDist[g.getArcs()[i].getPointA()])
                    {
                        minDist[g.getArcs()[i].getPointA()]= g.getArcs()[i].getTempsR()+ distanceTot;
                        TRI.push_back(g.getArcs()[i].getTempsR());
                    }
                }
            }
        }

        for(unsigned int i=0; i<ArcsParcourus.size(); i++)
        {

            if(ArcsParcourus[i].getTempsR()==TRI.front())
            {

                ArcsMarq[ArcsParcourus[i].getNum()-1]=true;
                sommetMarq[ArcsParcourus[i].getPointA()-1]=true;
                sommetD= ArcsParcourus[i].getPointA();
                distanceTot= distanceTot+ ArcsParcourus[i].getTempsR();

            }

        }

    }

    //std::cout<<"Distance totale: "<<distanceTot;
    for(unsigned int i=1; i<=g.getOrdre(); i++)
    {
        std::cout<<"Distance de votre position jusqu'au point "<<i<<" de la station: "<<minDist[i-1]/60<<std::endl;
    }

}

void dijkstra2(graphe g, int sommetD, int sommetA)
{
    /// DECLARATIONS
    std::vector<bool> sommetMarq;
    std::vector<bool> ArcsMarq;
    std:: vector<double> minDist; /// DISTANCE DU SOMMET DE DEPART AU SOMMET i
    std::vector<arcs> ArcsParcourus;
    int distanceTot=0;

    /// INITIALISATION

    /// TOUS LES SOMMETS NON MARQUES /// TOUS LES DISTANCES AU SOMMET DE DEPART A L'INFINI
    for(unsigned int i=0; i<g.getOrdre(); i++)
    {
        sommetMarq.push_back(false);  /// si non marqué -----> 0 si marqué -----> 1
        minDist.push_back(INT_MAX);
    }

    for(unsigned int i=0; i<g.getTaille(); i++)
    {
        ArcsMarq.push_back(false);
    }

    minDist[sommetD-1]=0;
    sommetMarq[sommetD-1]=true;

    //int min= INT_MAX, source= 0;

    /// DEBUT DE L'ALGORITHME

    while(ArcsParcourus.size()<g.getTaille())
    {
        std::list <double> TRI;

        for(unsigned int i=0; i<g.getTaille(); i++)
        {
            if(g.getArcs()[i].getPointD()== sommetD)     // SI L'ARC PART DU SOMMET DE DEPARt
            {
                if(sommetMarq[g.getArcs()[i].getPointA()-1]== false)                  // SI L'ARC N'EST PAS MARQUE
                {
                    ArcsParcourus.push_back(g.getArcs()[i]);

                    if(g.getArcs()[i].getTempsR() + distanceTot <minDist[g.getArcs()[i].getPointA()])
                    {
                        minDist[g.getArcs()[i].getPointA()]= g.getArcs()[i].getTempsR()+ distanceTot;
                        TRI.push_back(g.getArcs()[i].getTempsR());
                    }
                }
            }
        }

        for(unsigned int i=0; i<ArcsParcourus.size(); i++)
        {

            if(ArcsParcourus[i].getTempsR()==TRI.front())
            {

                ArcsMarq[ArcsParcourus[i].getNum()-1]=true;
                sommetMarq[ArcsParcourus[i].getPointA()-1]=true;
                sommetD= ArcsParcourus[i].getPointA();
                distanceTot= distanceTot+ ArcsParcourus[i].getTempsR();

            }

        }

    }

    std::cout<<"Distance de votre position jusqu'au point "<<sommetA<<" de la station: "<<minDist[sommetA-1]/60<<std::endl;


}
///********************************************FIN DIJKSTRA*************************************************///




///**********************************MENU 11***********************************///
void Menu11(graphe g)
{
    int choixMenu2;
    do
    {
        std::cout<<std::endl<<"		----------------------		"<<std::endl;
        std::cout<<std::endl<<" ------------------VOUS MANQUEZ DE TEMPS?--------------------"<<std::endl;
        std::cout<<std::endl<<"		----------------------		"<<std::endl<<std::endl;


        std::cout<<"	 1. Tous les plus courts chemins issus de votre position et leur duree "<<std::endl;
        std::cout<<"	 2. L'itineraire le plus rapide entre deux points "<<std::endl<<std::endl<<std::endl;
        std::cout<<"	 0. Revenir au menu Principal"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        std::cout<<"	  Veuillez entrer votre choix :    " ;

        std::cin>>choixMenu2;


        switch(choixMenu2)
        {
        case 0 :
            system("cls");
            Menu1(g);
            break;

        case 1 :
            system("cls");
            int D;
            std::cout<<"entrez votre point de depart: "<<std::endl;
            std::cin>>D;
            dijkstra(g,D);
            Retour11(g);

            break;

        case 2 :
            system("cls");
            int G,A;
            std::cout<<"entrez votre point de depart: "<<std::endl;
            std::cin>>G;
            std::cout<<"entrez votre point d'arrivee: "<<std::endl;
            std::cin>>A;
            dijkstra2(g,G,A);
            Retour11(g);
            break;

        }
    }
    while(choixMenu2!=0 && choixMenu2!=1 && choixMenu2!=2 );




}





///**********************************MENU 12***********************************///
void Menu12(graphe g) ///************* MENU D'AIDE ******************///
{
    /// DECLARATIONS
    int choixMenu2;
    std:: string nomTrajet;
    std:: string type;
    int point;
    /// FIN

    do
    {
        std::cout<<std::endl<<"		----------------------		"<<std::endl;
        std::cout<<std::endl<<" ------------------Aide--------------------"<<std::endl;
        std::cout<<std::endl<<"		----------------------		"<<std::endl<<std::endl;


        std::cout<<"	 1. Pour connaitre d'ou vous etes partis et ou vous allez"<<std::endl;
        std::cout<<"	 2. Tous les trajets qui menent a vous et les trajets que vous pouvez emprunter "<<std::endl<<std::endl<<std::endl;
        std::cout<<"	 0. Revenir au menu principal"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        std::cout<<"	  Veuillez entrer votre choix :    " ;


        std::cin>>choixMenu2;



        switch(choixMenu2)
        {

        case 0 :
            system("cls");
            Menu1(g);
            break;


        case 1 :
            std:: cout<< "Quel est le nom de votre trajet? "<<std::endl;
            std:: cin>> nomTrajet;
            std::cout<<""<<std::endl;
            std:: cout<< "Quel est le type de trajet ou vous etes? "<<std::endl;
            std:: cout<< "Si Piste Verte tapez V"<<std::endl;
            std:: cout<< "Si Piste Bleue tapez B"<<std::endl;
            std:: cout<< "Si Piste Rouge tapez R"<<std::endl; /// A CORRIGER
            std:: cout<< "Si Piste Noire tapez N"<<std::endl;
            std:: cout<< "Si Piste de Kilometre lance tapez KL"<<std::endl;
            std:: cout<< "Si Snowpark tapez SURF"<<std::endl;
            std:: cout<< "Si Navette tapez BUS"<<std::endl;
            std:: cout<< "Si Telepherique tapez TPH"<<std::endl;
            std:: cout<< "Si Telecabine tapez TC"<<std::endl;
            std:: cout<< "Si Telesiege debrayable tapez TSD"<<std::endl;
            std:: cout<< "Si Telesiege tapez TS"<<std::endl;
            std:: cout<< "Si Teleski tapez TK"<<std::endl;
            std:: cin>> type;

            for(unsigned int i=0; i<g.getTaille(); i++)
            {
                if(g.getArcs()[i].getNom()== nomTrajet && g.getArcs()[i].getType()== type)
                {
                    std :: cout<< "Le point de depart de votre trajet est: "<<g.getArcs()[i].getPointD()<< " et le point d'arrivee est: "<<g.getArcs()[i].getPointA()<<std:: endl;
                }
            }
            Retour12(g); /// POUR PAS QUE LE PROGRAMME S'ARRETE



        case 2 :
            std:: cout<<" Au niveau de quel point de la station etes vous?"<< std::endl;
            std:: cin>> point;
            for(unsigned int i=0; i<g.getTaille(); i++)
            {
                if(g.getArcs()[i].getPointD()== point)
                {
                    std :: cout<< "Vous pouvez emprunter le trajet: "<<g.getArcs()[i].getNom()<<std:: endl;
                }

                if(g.getArcs()[i].getPointA()== point)
                {
                    std :: cout<< "Le trajet: "<<g.getArcs()[i].getNom()<< "  mene a vous "<<std:: endl;

                }
            }
            Retour12(g); /// POUR PAS QUE LE PROGRAMME S'ARRETE
            break;

        default:
            system("cls");
            std::cout<<"Vous ne pouvez rentrer que les valeurs 0, 1 et 2"<<std::endl;
            Menu12(g);
            break;
        }
        system("cls");
    }
    while (choixMenu2!=0 && choixMenu2!=1 && choixMenu2!=2 );
}

///**********************************MENU 13***********************************///
void Menu13(graphe g)
{
    int choixMenu2;
    do
    {
        std::cout<<std::endl<<"                ----------------------                            "<<std::endl;
        std::cout<<std::endl<<" -------------PREFERENCES NIVEAU DE SKI--------------------"<<std::endl;
        std::cout<<std::endl<<"                           ----------------------                            "<<std::endl<<std::endl;
        std::cout<<"               1. Niveau debutant : Pistes vertes et bleues"<<std::endl;
        std::cout<<"               2. Niveau intermediaire : Pistes vertes a rouges  "<<std::endl;
        std::cout<<"               3. Niveau competition : Toutes les pistes ainsi que le Km lance et le snowpark  "<<std::endl<<std::endl<<std::endl;
        std::cout<<"               0. Revenir au menu principal"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        std::cout<<"                 Veuillez entrer votre choix :    " ;
        std::cin>>choixMenu2;

        int A;
        std::vector<arcs>Trajet;
        int B;
        std::vector<arcs>Trajet2;
        int C;
        std::vector<arcs>Trajet3;
        switch(choixMenu2)
        {
        case 0 :
            system("cls");
            Menu1(g);
            break;

        case 1 :
            system("cls");

            std::cout<<"entrez votre point de depart: "<<std::endl;
            std::cin>>A;
            while(Trajet.size()<=2)
            {
                for(unsigned int i=0; i<g.getTaille(); i++)
                {
                    if(g.getArcs()[i].getPointD()== A)
                    {
                        if((g.getArcs()[i].getType()=="V")||(g.getArcs()[i].getType()=="B"))
                        {
                            Trajet.push_back(g.getArcs()[i]);
                            A= g.getArcs()[i].getPointA();
                        }
                    }
                }
            }
            std::cout<<"Votre chemin: "<<std::endl;
            for(unsigned int i=0; i<Trajet.size(); i++)
            {
                std::cout<<"------->"<<Trajet[i].getNom();
            }
            Retour13(g);
            break;

        case 2 :
            system("cls");

            std::cout<<"entrez votre point de depart: "<<std::endl;
            std::cin>>B;
            while(Trajet2.size()<=2)
            {
                for(unsigned int i=0; i<g.getTaille(); i++)
                {
                    if(g.getArcs()[i].getPointD()== B)
                    {
                        if((g.getArcs()[i].getType()=="V")||(g.getArcs()[i].getType()=="B")||(g.getArcs()[i].getType()=="R"))
                        {
                            Trajet.push_back(g.getArcs()[i]);
                            B= g.getArcs()[i].getPointA();
                        }
                    }
                }
            }
            std::cout<<"Votre chemin: "<<std::endl;
            for(unsigned int i=0; i<Trajet2.size(); i++)
            {
                std::cout<<"------->"<<Trajet2[i].getNom();
            }
            Retour13(g);
            break;

        case 3 :
            system("cls");

            std::cout<<"entrez votre point de depart: "<<std::endl;
            std::cin>>C;
            while(Trajet3.size()<=2)
                for(unsigned int i=0; i<g.getTaille(); i++)
                {
                    if(g.getArcs()[i].getPointD()== C)
                    {
                        if((g.getArcs()[i].getType()=="V")||(g.getArcs()[i].getType()=="B")||(g.getArcs()[i].getType()=="R")||(g.getArcs()[i].getType()=="N")||(g.getArcs()[i].getType()=="KL")||(g.getArcs()[i].getType()=="SURF"))
                        {
                            Trajet3.push_back(g.getArcs()[i]);
                            C= g.getArcs()[i].getPointA();
                        }
                    }
                }
            std::cout<<"Votre chemin: "<<std::endl;
            for(unsigned int i=0; i<Trajet3.size(); i++)
            {
                std::cout<<"------->"<<Trajet3[i].getNom();
            }
            Retour13(g);
            break;


        }
    }
    while(choixMenu2!=0 && choixMenu2!=1 && choixMenu2!=2 && choixMenu2!=3 );




}




///**********************************MENU 1***********************************///
void Menu1(graphe g)

{
    int choixMenu1 ;
    do
    {


        std::cout<<"	~~~~Emmanuel Salameh & Maxime Domecq~~~~"<<std::endl;
        std::cout<<std::endl<<"		----------------------		"<<std::endl;
        std::cout<<std::endl<<" ------------------BORNE INTERACTIVE--------------------"<<std::endl;
        std::cout<<std::endl<<"		----------------------		"<<std::endl<<std::endl;


        std::cout<<"	 1. Vous manquez de temps?"<<std::endl;
        std::cout<<"	 2. Un itineraire adapte pour vous"<<std::endl;
        std::cout<<"	 3. Aide "<<std::endl<<std::endl<<std::endl;
        std::cout<<"	 0. Quitter l'interface"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        std::cout<<"	  Veuillez entrer votre choix :    " ;

        std::cin>>choixMenu1;

        switch(choixMenu1)
        {
        case 0 :
            exit (EXIT_FAILURE);
            break;

        case 1 :
            system("cls");
            Menu11(g); /// BFS ET DIJKSTRA
            break;

        case 2 :
            system("cls");
            Menu13(g);
            break;

        case 3 :
            system("cls");
            Menu12(g); /// AIDE
            break;

            break;
        }
        system("cls");
    }
    while (choixMenu1!=0 && choixMenu1!=1 && choixMenu1!=2 && choixMenu1!=3 );
}

///**********************************RETOUR 13***********************************///
void Retour13(graphe g)
{
    int choix;
    do
    {
        std::cout<<std::endl;
        std::cout<<"	 1. Revenir au menu de chemin selon les preferences "<<std::endl<<std::endl;
        std::cout<<"	 2. Revenir au menu principal"<<std::endl<<std::endl;
        std::cout<<"	 0. Quitter l'interface"<<std::endl<<std::endl;
        std::cout<<"	 Faites votre choix"<<std::endl<<std::endl;
        std:: cin>> choix;
        switch(choix)
        {
        case 1:
            system("cls");
            Menu13(g);
            break;
        case 2:
            system("cls");
            Menu1(g);
            break;
        case 0:
            exit (EXIT_FAILURE);
            break;
        }
        system("cls");
    }
    while (choix!=0 && choix!=1 && choix!=2 );
}

///**********************************RETOUR 12***********************************///
void Retour12(graphe g)
{
    int choix;
    do
    {

        std::cout<<"	 1. Revenir au menu d'aide"<<std::endl<<std::endl;
        std::cout<<"	 2. Revenir au menu principal"<<std::endl<<std::endl;
        std::cout<<"	 0. Quitter l'interface"<<std::endl<<std::endl;
        std::cout<<"	 Faites votre choix"<<std::endl<<std::endl;
        std:: cin>> choix;
        switch(choix)
        {
        case 1:
            system("cls");
            Menu12(g);
            break;
        case 2:
            system("cls");
            Menu1(g);
            break;
        case 0:
            exit (EXIT_FAILURE);
            break;
        }
        system("cls");
    }
    while (choix!=0 && choix!=1 && choix!=2 );
}

///**********************************RETOUR 11***********************************///
void Retour11(graphe g)
{
    int choix;
    do
    {

        std::cout<<"	 1. Revenir au menu de chemin rapide"<<std::endl<<std::endl;
        std::cout<<"	 2. Revenir au menu principal"<<std::endl<<std::endl;
        std::cout<<"	 0. Quitter l'interface"<<std::endl<<std::endl;
        std::cout<<"	 Faites votre choix"<<std::endl<<std::endl;
        std:: cin>> choix;
        switch(choix)
        {
        case 1:
            system("cls");
            Menu11(g);
            break;
        case 2:
            system("cls");
            Menu1(g);
            break;
        case 0:
            exit (EXIT_FAILURE);
            break;
        }
        system("cls");
    }
    while (choix!=0 && choix!=1 && choix!=2 );
}



int main()
{

    std:: string const nomFichier("C:/users/admin/holloway/INFO_SKI/arcs.txt");
    graphe g{nomFichier};
    Menu1(g);
    //dijkstra(g,31);
    return 0;
}
//c:\users\admin\holloway\INFO_SKI\arcs.txt
