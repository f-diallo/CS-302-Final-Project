#ifndef CITY_H_
#define CITY_H_
#include <string>

class City {

    private:

        std::string m_city;

    public:

        City();
        City(std::string & city);
        City(City & other);
        ~City();

        std::string getCity();
        void setCity(std::string & city);

        City & operator = (City & rhs);
 

};

#include "City.cpp"

#endif