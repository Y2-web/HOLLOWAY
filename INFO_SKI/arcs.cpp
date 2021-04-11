#include "arcs.h"



arcs:: arcs()
{

}

arcs:: arcs(int _num,std:: string _nom, std:: string _type,int _pointD, int _pointA, int _tempsR)
{
    m_num= _num;
    m_nom= _nom;
    m_type= _type;
    m_pointD = _pointD;
    m_pointA = _pointA;
    m_tempsR= _tempsR;
}

arcs:: ~arcs()
{

}
int arcs:: getNum() const
{
    return m_num;
}

int arcs::getPointD() const
{
    return m_pointD;
}

int arcs::getPointA() const
{
    return m_pointA;
}

std::string arcs:: getNom() const
{
    return m_nom;
}

std::string arcs:: getType() const
{
    return m_type;
}

double arcs:: getTempsR() const
{
    return m_tempsR;
}
