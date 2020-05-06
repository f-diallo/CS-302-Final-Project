/*
********************
* 1. HAVE HOMEBREW INSTALLED.
* 2. HAVE BOOST HOMEBREW PACKAGE INSTALLED FOR DEVELOPMENT.
* 3. __(class) DENOTES A USER CREATED CLASS.
* 4. MAKE SURE NO GLOBAL NAMESPACES ARE USED SUCH AS boost AND std.
* 5. __city AND __distance ARE ADVANCED STRUCTS.
* 6. RELATIVE DIRECTORIES ARE USED.
********************
*/
#ifndef __CITY_H_
#define __CITY_H_
#include <iostream>
#include <string>

class __city {

    private:

        std::string m_city;

    public:

        __city(): m_city("NA") { }

        __city(std::string city): m_city(city) { }

        std::string getCity() {

            return m_city;

        }

        __city & operator = (__city & rhs) {

            m_city = rhs.m_city;

            return *this;

        }

};

#endif