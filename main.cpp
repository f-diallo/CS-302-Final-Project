//Boost Graph Library test
#include <iostream>                 // for std::cout
#include <utility>                  // for std::pair
#include <string>                   //for std:: string
#include <fstream>					//for std::ofstream
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/array.hpp>
#include <fstream>

using namespace std;
using namespace boost;

//function declaration
void allPossiblePaths(char a[], int size, int n, ofstream & fout);
typedef adjacency_list<listS, vecS, directedS, string, property<edge_weight_t, int> > Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor vertexType;
typedef boost::graph_traits<Graph>::edge_descriptor edgeType;
typedef boost::graph_traits<Graph>::edge_iterator edgeIterator;
typedef boost::graph_traits<Graph>::vertex_iterator vertexIterator;

int main()
{
    
    Graph G;
    property_map<Graph, boost::edge_weight_t>::type weightmap = get(boost::edge_weight, G);
    
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
    
    edgeType RNO_SFO_route = add_edge(RNO_location, SFO_location, G).first;
    weightmap[RNO_SFO_route] = 220;
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
    
    property_map<Graph, vertex_index_t>::type idmap = get(vertex_index, G);
    vector<vertexType> predecessors(num_vertices(G));
    vector<int> distances(num_vertices(G));
    dijkstra_shortest_paths(G, RNO_location, boost::weight_map(get(edge_weight, G)).distance_map(make_iterator_property_map(distances.begin(), idmap))
        .predecessor_map(make_iterator_property_map(predecessors.begin(), idmap))
    );
    
    float totalCost = 0;
    float cpg = 2.59;
    int mpgValue = 40;
    float totalMiles = 0;

    for (int index = 0; index < 5; index++) {
        
        totalMiles += distances[index];
        
    }
    
    totalMiles /= mpgValue;
    totalCost = totalMiles * cpg;
    
	//output

	typedef property_map<Graph, vertex_index_t>::type IndexMap;
	IndexMap index= get(vertex_index, G);

	cout<<"Edges(G):\n";
	edgeIterator ei, ei_end;
	for(tie(ei, ei_end)= edges(G); ei!=ei_end; ++ei)
	{
		cout<<"(" << index[source(*ei, G)];
		cout<<", "<< index[target(*ei, G)];
		cout<<")" << endl;
	}

	ofstream fout;
	fout.open("GraphOutput.txt");

	char test[5]={"BCDE"};
    allPossiblePaths(test, 4, 4, fout);
    
    fout << "Shortest Distance cost is $" << totalCost << "."  << endl;


	fout.close();
    

    return 0;
    
}

//still need to add mileage
void allPossiblePaths(char * a, int size, int n, ofstream & fout)
{

	if(size==1){
		//float mileage=0, mpg= 40, ppg=2.59;
		fout<<"A-> ";
		for(int j=0; j<4; j++){
			fout<<a[j]<<"-> ";
		}
		fout<<"A"<<endl;
		//fout<<"Mileage: "<<mileage<<"\tCost: "<<mileage*ppg/mpg<<endl;
		return;
	}

	for(int i=0; i<size; i++)
	{
		allPossiblePaths(a, size-1, n, fout);
		//if size is odd, swap first and last
		if(size%2==1)
			swap(a[0], a[size-1]);
		else	//swap current element and last
			swap(a[i], a[size-1]);
	}

}
