#include <iostream>
#include <string>
#include "City.h"

City::City(): m_city("NA") { }

City::City(std::string & city): m_city(city) { }

City::City(City & other): m_city(other.m_city) { }

std::string City::getCity() {

    return m_city;

}

void City::setCity(std::string & city) {

    m_city = city;

}

City & City::operator = (City & rhs) {

    m_city = rhs.m_city;
    return *this;

}

