//Boost Graph Library test
#include <iostream>                 // for std::cout
#include <utility>                  // for std::pair
#include <string>                   //for std:: string
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace std;
using namespace boost;


int main()
{

// create a typedef for the Graph type
//typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;
typedef adjacency_list<listS, vecS, directedS, 
                       no_property, property<edge_weight_t, int> > Graph;

//example: NYC="New York City";
string RNO="Reno", SF="San Francisco", SLC="Salt Lake City", SEA="Seattle", LV="Las Vegas";

//Make labels for vertices
const int numCities=5;

//write out edges for graph
typedef pair<string, string> Distance;
Distance distances[]=
{ Distance(RNO, SLC), Distance(RNO, SEA), 
  Distance(RNO, LV), Distance(SF, SLC), 
  Distance(SF, SEA), Distance(SF, LV), 
  Distance(SLC, SEA), Distance(SLC, LV), 
  Distance(SEA, LV)};

const int numEdges= sizeof(distances)/sizeof(distances[0]);

//add weight/mileage to edges/distances
int mileages[]= {520, 700, 440, 740, 800,
                 570, 840, 420, 1100};


//declare graph object and add edges to graph object
Graph G(distances, distances + sizeof(distances)/sizeof(Distance), mileages, numCities);

//all we have to do is create a graph, figure out all the possible paths by brute force
//and find the shortest path by algorithm, output to .txt file

/*
//output

// get the property map for vertex indices
typedef property_map<Graph, edge_index_t>::type IndexMap;
IndexMap index = get(edge_index, G);

cout << "edges(G) =";
graph_traits<Graph>::edge_iterator ei;
graph_traits<Graph>::edge_iterator ei_end;
for(tie(ei, ei_end) = edges(G); ei != ei_end; ++ei){
    cout << "("<< index[source(*ei , G)];
    cout << ","<< index[target(*ei , G)];
    cout << ")"<< endl;

}

//7:03
*/

return 0;
}