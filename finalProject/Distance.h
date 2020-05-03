#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "City.h"

class Distance {

    private:

        City m_city1;
        City m_city2;
        int m_mileage;

    public:

        Distance();
        Distance(City city1, City city2, int mileage);
        Distance(Distance & other);
        ~Distance();

        City getCity1();
        City getCity2();
        int getMileage();

        void setCity1(City & city1);
        void setCity2(City & city2);
        void setMileage(int mileage);


};

#endif