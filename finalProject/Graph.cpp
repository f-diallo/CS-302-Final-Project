#include <iostream>
#include "Graph.h"

Graph:: Graph()       //initialize cities and distances
:m_cities(nullptr), m_distances(nullptr)
{}
Graph:: Graph(City * cities, Distance * distances)
:m_cities(cities), m_distances(distances)
{}

Graph:: Graph(Graph & other)
:m_cities(other.m_cities), m_distances(other.m_distances)
{}

Graph:: ~Graph()
{}


int Graph:: getNumCities()
{
	int size = *(&m_cities + 1) - m_cities; 
	return size;

}

int Graph:: getNumDistances()
{
	int size = *(&m_distances + 1) - m_distances; 
	return size;

}

int Graph:: getEdgeWeight(City start, City end)
{


}


bool Graph:: isEmpty()
{


}

bool Graph:: edgeExists(City start, City end)
{


}


void Graph:: addDistance(City start, City end, int mileage)   //create distance object in it
{


}

void Graph:: addCity(City newCity)    //checks if city exists also
{


}

void Graph:: removeDistance(City start, City end)   //removes distance
{


}

void Graph:: removeCity(City oldCity)  // redirects distances
{


}

void Graph:: clear()
{


}



Graph & Graph:: operator=(Graph & rhs)
{


}

int Graph:: shortestPath(City start, City end)   //required???       yep
{


}


void Graph:: depthFirstTraversal(City start)
{


}

void Graph:: breadFirstTraversal(City start)
{


}



void Graph:: allPossiblePaths(){
/*outputs paths[]={path1(*cites, mileage),...}; 
//each path has an array of cities in the order the path was taken and the length/mileage of the path
acbde,acbed,acdeb,acdbe,acebd,acedb,
adbce,adbec,adceb,adcbe,adebc,adecb,
aebcd,aebdc,aecdb,aecbd,aedbc,aedcb
if you have to return to reno, that eliminates all paths that end w/ b, leaving 12
acbde,acbed,acdbe,acebd,
adbce,adbec,adcbe,adebc,
aebcd,aebdc,aecbd,aedbc
while finding paths store path w/ lowest mileage to find shortest path
*/

}
