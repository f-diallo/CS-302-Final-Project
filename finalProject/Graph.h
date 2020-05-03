//Graph.h
#ifndef GRAPH_H_
#define GRAPH_H_

#include "City.h"
#include "Distance.h"

class Graph{
    private:
        City *m_cities;
        Distance *m_distances;
    
    public:
        Graph();       //initialize cities and distances
        Graph(City * cities, Distance * distances);
        Graph(Graph & other);
        ~Graph();

        int getNumCities();
        int getNumDistances();
        int getEdgeWeight(City start, City end);

        bool isEmpty();
        bool edgeExists(City start, City end);

        void addDistance(City start, City end, int mileage);   //create distance object in it
        void addCity(City newCity);    //checks if city exists also
        void removeDistance(City start, City end);   //removes distance
        void removeCity(City oldCity);  // redirects distances
        void clear();

        Graph & operator=(Graph & rhs);
        int shortestPath(City start, City end);   //required???       yep

        void depthFirstTraversal(City start);
        void breadFirstTraversal(City start);

        void allPossiblePaths();

};


#endif //GRAPH_H_