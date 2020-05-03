#include <iostream>
#include "Distance.h"

Distance::Distance(): m_mileage(0) { }

Distance::Distance(City city1, City city2, int mileage): m_city1(city1), m_city2(city2), m_mileage(0) { }

Distance::Distance(Distance & other): m_city1(other.m_city1), m_city2(other.m_city2), m_mileage(other.m_mileage) { }

Distance::~Distance() { }

City Distance::getCity1() {

    return m_city1;

}

City Distance::getCity2() {

    return m_city2;

}

int Distance::getMileage() {

    return m_mileage;

}

void Distance::setCity1(City & city1) {

    m_city1 = city1;

}

void Distance::setCity2(City & city2) {

    m_city2 = city2;

}

void Distance::setMileage(int mileage) {

    m_mileage =  mileage;

}