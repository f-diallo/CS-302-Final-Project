#include <iostream>
#include <string>
#include "City.h"

City::City(): m_city("NA") { }

City::City(std::string & city): m_city(city) { }

City::City(City & other): m_city(other.m_city) { }

City::~City() {}

std::string City::getCity() {

    return m_city;

}

void City::setCity(std::string & city) {

    m_city = city;

}

bool City::operator== (City & rhs){

	if(m_city.compare(rhs.m_city)==0)
		return true;
	else
		return false;

}
