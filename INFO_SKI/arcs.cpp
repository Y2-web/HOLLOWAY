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
