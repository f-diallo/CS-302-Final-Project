
#ifndef GRAPH_H_
#define GRAPH_H_

#include "City.h"
#include "Distance.h"

class Graph{
    private:
        City m_cities[5];
        Distance m_distances[9];
    
    public:
        Graph();       //initialize cities and distances
        Graph(City * cities, Distance * distances);
        Graph(Graph & other);
        ~Graph();

        int getNumCities();
        int getNumEdges();
        int getEdgeWeight(City start, City end);

        bool isEmpty();
        bool edgeExists(City start, City end);

        void addDistance(City start, City end, int mileage);   //create distance object in it
        void addCity(City newCity);    //checks if city exists also
        void removeDistance(City start, City end);   //removes distance
        void removeCity(City oldCity);  // redirects distances
        void clear();

        Graph & operator=(Graph & rhs);
        //Int shortestPath(City start, City end)   //required???

        void depthFirstTraversal(City start);
        void breadFirstTraversal(City start);

        void allPossiblePaths();

};

#include "Graph.cpp"

#endif //GRAPH_H_