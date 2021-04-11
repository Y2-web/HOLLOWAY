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

int sommet:: getAltitude() const
{
    return m_altitude;
}

