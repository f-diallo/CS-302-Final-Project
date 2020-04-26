# CS-302-Final-Project
Traveling Salesman Problem-Graphs

Consider 5 cities of interest, namely 
	a) Reno, 
	b) San Francisco,
	c) Salt Lake City, 
	d)Seattle, and 
	e) Las Vegas. 
Use information on the road network and derive the miles from one city to the other. 
Assume a fixed metric of Miles Per Gallon = 40 and derive the cost of each transition in terms of miles. 

Then on that basis, conduct the following:
		-Create a graph with each of its vertices corresponding to one of these cities and its
	edges being weighted by the associated miles for each trip. Note that if (and only if)
	to go from city A to B you must go through C then you must add one edge from A
	to C and one edge from C to B and there is no need to add an edge directly from
	A to B.
		-Solve the Traveling Salesman Problem such that traveling salesman starts from Reno,
	visits all cities in the above list and returns to list. Solve this problem in the brutal
	force-way, i.e. by identifying all possible paths.

Submit your solution in terms of a) code, and b) a *.txt all possible paths and the best
one selected by the algorithm.

Note: You may use – if you want to – the Boost Graph Library.
