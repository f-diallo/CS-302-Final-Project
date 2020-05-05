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
#ifndef __DISTANCE_H_
#define __DISTANCE_H_
#include <iostream>

class __distance {

    private:

        int m_distance;

    public:

        __distance(): m_distance(0) { }

        __distance(int distance): m_distance(distance) { }

        int getDistance() {

            return m_distance;

        }

        __distance & operator = (__distance & rhs) {

            m_distance = rhs.m_distance;

            return *this;

        }

};

#endif