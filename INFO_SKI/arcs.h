#ifndef ARCS_H_INCLUDED
#define ARCS_H_INCLUDED
#include "sommet.h"


class arcs
{
private:
    int m_num;
    std:: string m_nom;
    std:: string m_type;
    int m_pointD;
    int m_pointA;
    double m_tempsR;
public:
    arcs();
    arcs(int _num,std:: string _nom, std:: string _type,int _pointD, int _pointA, int _tempsR);
    ~arcs();
    int getNum() const;
    int getPointD() const;
    int getPointA() const;
    std::string getNom() const;
    std::string getType() const;
     double getTempsR() const;

};


#endif // ARCS_H_INCLUDED
