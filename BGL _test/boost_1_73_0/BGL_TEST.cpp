//Boost Graph Library test
#include <iostream>                 // for std::cout
#include <utility>                  // for std::pair
#include <string>                   //for std:: string
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>

using namespace std;
using namespace boost;


int main()
{

    typedef adjacency_list<listS, vecS, directedS, string, property<edge_weight_t, int>> Graph;
    typedef boost::graph_traits<Graph>::vertex_descriptor vertexType;
    typedef boost::graph_traits<Graph>::edge_descriptor edgeType;
    typedef boost::graph_traits<Graph>::edge_iterator edgeIterator;
    typedef boost::graph_traits<Graph>::vertex_iterator vertexIterator;
    
    Graph G;
    boost::property_map<Graph, boost::edge_weight_t>::type weightmap = get(boost::edge_weight, G);
    
    vertexType SFO_location = add_vertex(G);
    G[SFO_location] = "San Francisco";
    vertexType RNO_location = add_vertex(G);
    G[RNO_location] = "Reno";
    vertexType SLC_location = add_vertex(G);
    G[SLC_location] = "Salt Lake City";
    vertexType SEA_location = add_vertex(G);
    G[SEA_location] = "Seattle";
    vertexType LAS_location = add_vertex(G);
    G[LAS_location] = "Las Vegas";
    
    edgeType RNO_SLC_route = add_edge(RNO_location, SLC_location, G).first;
    weightmap[RNO_SLC_route] = 520;
    edgeType RNO_SEA_route = add_edge(RNO_location, SEA_location, G).first;
    weightmap[RNO_SEA_route] = 700;
    edgeType RNO_LAS_route = add_edge(RNO_location, LAS_location, G).first;
    weightmap[RNO_LAS_route] = 440;
    edgeType SFO_SEA_route = add_edge(SFO_location, SEA_location, G).first;
    weightmap[SFO_SEA_route] = 740;
    edgeType SFO_SLC_route = add_edge(SFO_location, SLC_location, G).first;
    weightmap[SFO_SLC_route] = 800;
    edgeType SFO_LAS_route = add_edge(SFO_location, LAS_location, G).first;
    weightmap[SFO_LAS_route] = 570;
    edgeType SLC_SEA_route = add_edge(SLC_location, SEA_location, G).first;
    weightmap[SLC_SEA_route] = 840;
    edgeType SLC_LAS_route = add_edge(SLC_location, LAS_location, G).first;
    weightmap[SLC_LAS_route] = 420;
    edgeType SEA_LAS_route = add_edge(SEA_location, LAS_location, G).first;
    weightmap[SEA_LAS_route] = 1100;

    
    
    

    
    
    
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
*/
//7:03


return 0;
}
