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

using namespace std;
using namespace boost;

//function declaration
void allPossiblePaths(char a[], int size, int n, ofstream & fout);
int findMileage(char * a);
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

float findMileage(char * a)
{
	float mileage=0;
	char first='A', second=a[0];
	for(int i=1; i<5; i++)
	{

		if(first=='A')
		{
			if(second=='B')
				mileage+=220;
			else if(second=='C')
				mileage+=520;
			else if(second=='D')
				mileage+=700;
			else if(second=='E')
				mileage+=440;
		}
		else if(first=='B')
		{
			if(second=='A')
				mileage+=220;
			else if(second=='C')
				mileage+=800;
			else if(second=='D')
				mileage+=740;
			else if(second=='E')
				mileage+=570;
		}
		else if(first=='C')
		{
			if(second=='A')
				mileage+=520;
			else if(second=='B')
				mileage+=800;
			else if(second=='D')
				mileage+=840;
			else if(second=='E')
				mileage+=420;
		}
		else if(first=='D')
		{
			if(second=='A')
				mileage+=700;
			else if(second=='B')
				mileage+=740;
			else if(second=='C')
				mileage+=840;
			else if(second=='E')
				mileage+=1100;
		}
		else if(first=='E')
		{
			if(second=='A')
				mileage+=440;
			else if(second=='B')
				mileage+=570;
			else if(second=='C')
				mileage+=420;
			else if(second=='D')
				mileage+=1100;
		}
		first=a[i-1];
		second=a[i];
	}
	//return trip
		if(a[3]=='B')
			mileage+=220;
		else if(a[3]=='C')
			mileage+=520;
		else if(a[3]=='D')
			mileage+=700;
		else if(a[3]=='E')
			mileage+=440;

	return mileage;
}


