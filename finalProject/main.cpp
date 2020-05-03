
#include <iostream>
#include "City.h"
#include "Distance.h"
#include "Graph.h"

using namespace std;


int main()
{
//example: City X("New York");
string RNO="Reno", SF="San Francisco", SLC="Salt Lake City", SEA="Seattle", LV="Las Vegas";
City A(RNO), B(SF), C(SLC), D(SEA), E(LV);

City cities[5]={A, B, C, D, E};

//example: Distance AC(city1, city2, mileage)
Distance AC(A, C, 520), AD(A, D, 700), AE(A, E, 440), BC(B, C, 740), BD(B, D, 800), BE(B, E, 570), CD(C, D, 840), CE(C, E, 420), DE(D, E, 1100);

Distance distances[9]={AC, AD, AE, BC, BD, BE, CD, CE, DE};

//create graph
Graph myGraph(cities, distances);

//Assume a fixed metric of Miles Per Gallon = 40 and derive the cost of each transition in terms of miles.

//print by way of brute force all possible paths from Reno to pass through all of the cities
//print all paths to output file



//indicate which path is the shortest one


return 0;
}