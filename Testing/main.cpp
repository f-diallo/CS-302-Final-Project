
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
#include <iostream>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>

#include "__city/__city.h" 
#include "__map/__map.h" 

int main(void) {

    std::string cityCodes[5] = { "RNO", "SFO", "SLC", "SEA", "LAS" };

    __city locations[5] = { cityCodes[0],  cityCodes[1], cityCodes[2], cityCodes[3], cityCodes[4] };
    __distance AC(520), AD(700), AE(440), BC(740), BD(800), BE(570), CD(840), CE(420), DE(1100);
    __map bestCoast;


    bestCoast.addDistance(locations[0], locations[2], AC);





    return 0;

}