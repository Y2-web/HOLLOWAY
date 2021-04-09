#include "arcs.h"



arcs:: arcs()
{

}

arcs:: arcs(int _num,std:: string _nom, std:: string _type,int _pointD, int _pointA)
{
    m_num= _num;
    m_nom= _nom;
    m_type= _type;
    m_pointD = _pointD;
    m_pointA = _pointA;
}

arcs:: ~arcs()
{

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
