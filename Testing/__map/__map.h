/*
********************
* 1. HAVE HOMEBREW INSTALLED.
* 2. HAVE BOOST HOMEBREW PACKAGE INSTALLED FOR DEVELOPMENT.
* 3. __(class) DENOTES A USER CREATED CLASS.
* 4. MAKE SURE NO GLOBAL NAMESPACES ARE USED SUCH AS boost AND std.
* 5. __city AND __distance ARE ADVANCED STRUCTS.
* 6. RELATIVE DIRECTORIES ARE USED.
********************

********************
* NOTE: THIS FILE FUNCTIONS WILL BE IN A .cpp SOON.
********************
*/
#ifndef __MAP_H_
#define __MAP_H_
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>

#include "../__city/__city.h"
#include "../__distance/__distance.h"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, __city, __distance> graphType;
typedef boost::graph_traits<graphType>::vertex_descriptor vertexType;
typedef boost::graph_traits<graphType>::edge_descriptor edgeType;
typedef boost::graph_traits<graphType>::edge_iterator edgeIterator;
typedef boost::graph_traits<graphType>::vertex_iterator vertexIterator;

class __map {

    private:

        graphType m_map;


    public:

        int get_cityCount() {

            return num_vertices(m_map);

        }
        int get_routeCount() {

            return num_edges(m_map);

        }

        void addDistance(__city sourceCity, __city destinationCity, __distance distance) {

            vertexType sourceCity_location = boost::add_vertex(sourceCity, m_map);
            vertexType destinationCity_location = boost::add_vertex(destinationCity, m_map);
            edgeType distance_route = boost::add_edge(sourceCity_location, destinationCity_location, distance, m_map).first;
            return;

        }
        void removeDistance(__city sourceCity, __city destinationCity) {

            return;

        }
        void clear() {


        }
        

};

#endif