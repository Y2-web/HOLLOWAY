#include "graphe.h"
//void Menu11();
//void Menu12();


/*void RetourMenu11()
{
    system("cls");
    Menu11();

}



void Consultation()
{
    system("cls");
    int saisieConsul;
    //std::cout<<"consultation test"<<std::endl;
    std::cout<<"tapez 0 pour retour au menu precedent"<<std::endl;
    std::cin>>saisieConsul;
    if (saisieConsul==0)
    {
        RetourMenu11();
    }

}

void ModifierTemps()
{
    system("cls");
    int saisieTemps;
    //std::cout<<"consultation test"<<std::endl;
    std::cout<<"tapez 0 pour retour au menu precedent"<<std::endl;
    std::cin>>saisieTemps;
    if (saisieTemps==0)
    {
        RetourMenu11();
    }


}





void RetourMenu12()
{
    system("cls");
    Menu12();

}*/

/*void Menu11()
{
    std::cout<<std::endl<<"		----------------------		"<<std::endl;
    std::cout<<std::endl<<" ------------------PISTES ET REMONTEES--------------------"<<std::endl;
    std::cout<<std::endl<<"		----------------------		"<<std::endl<<std::endl;


    std::cout<<"	 1. Quel est ce trajet ? "<<std::endl;
    std::cout<<"	 2. A partir de ce point ? "<<std::endl<<std::endl<<std::endl;
    std::cout<<"	 0. Revenir au menu Principal"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
    std::cout<<"	  Veuillez entrer votre choix :    " ;
    int choixMenu2;
    std::cin>>choixMenu2;

    if (choixMenu2!=0 && choixMenu2!=1 && choixMenu2!=2 )
    {
        std::cout<<"votre choix n'est pas correct, reesayez : "<<std::endl;
        system("cls");
        Menu11();
    }

    do
    {
        switch(choixMenu2)
        {
        case 0 :
            RetourMenu1();
            break;

        case 1 :
            Consultation()  ;
            break;

        case 2 :
            ModifierTemps()   ;
            break;

            break;
        }
    }
    while(choixMenu2!=0);




}*/

void Retour(graphe g);

void Menu1(graphe g);
void Menu12(graphe g) ///************* MENU D'AIDE ******************///
{
    /// DECLARATIONS
    int choixMenu2;
    std:: string nomTrajet;
    std:: string type;
    int point;
    /// FIN

    do{
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
        Retour(g); /// POUR PAS QUE LE PROGRAMME S'ARRETE



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
        Retour(g); /// POUR PAS QUE LE PROGRAMME S'ARRETE
        break;

    default:
        system("cls");
        std::cout<<"Vous ne pouvez rentrer que les valeurs 0, 1 et 2"<<std::endl;
        Menu12(g);
        break;
    }
    system("cls");
}while (choixMenu2!=0 && choixMenu2!=1 && choixMenu2!=2 );
}





void Menu1(graphe g)

{
    int choixMenu1 ;
    do{


    std::cout<<"	~~~~Emmanuel Salameh & Maxime Domecq~~~~"<<std::endl;
    std::cout<<std::endl<<"		----------------------		"<<std::endl;
    std::cout<<std::endl<<" ------------------BORNE INTERACTIVE--------------------"<<std::endl;
    std::cout<<std::endl<<"		----------------------		"<<std::endl<<std::endl;


    std::cout<<"	 1. Consulter l'ensemble des pistes et remontees"<<std::endl;
    std::cout<<"	 2. Aide "<<std::endl<<std::endl<<std::endl;
    std::cout<<"	 0. Quitter l'interface"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
    std::cout<<"	  Veuillez entrer votre choix :    " ;

    std::cin>>choixMenu1;

    switch(choixMenu1)
    {
    case 0 :
        exit (EXIT_FAILURE);
        break;

    case 1 :
        //Menu11();
        break;

    case 2 :
        system("cls");
        Menu12(g); /// AIDE
        break;

        break;
    }
    system("cls");
    }while (choixMenu1!=0 && choixMenu1!=1 && choixMenu1!=2 );
}


void Retour(graphe g)
{
    int choix;
    do{

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
    }while (choix!=0 && choix!=1 && choix!=2 );
}


int main()
{

    std:: string const nomFichier("C:/users/admin/holloway/INFO_SKI/arcs.txt");
    graphe g{nomFichier};
    Menu1(g);
    return 0;
}
//c:\users\admin\holloway\INFO_SKI\arcs.txt
