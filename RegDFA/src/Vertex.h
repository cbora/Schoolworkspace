/*
 * Vertex.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Deverick
 */

#ifndef VERTEX_H_
#define VERTEX_H_
#include <string>
#include <vector>

using namespace std;
/*
 * stateId refers to the current state
 * Struct will represent a state node within the ADJList
 */

class Vertex;

struct State{
	int stateId;
	bool rootState;
	bool finalState;
};

class Edge{
private:
	char weight;
public:
	Vertex *vertexTo;
	//CONSTRUCTOR
	Edge(Vertex *vertexTo, char weight);

	//GETTER METHODS maybe a set
	Vertex* returnToVertex(){
		return vertexTo;
	}
	char returnWeight(){
		return weight;
	}
};

class Vertex{
public:
	State thisState;
	Edge *out;
	Vertex();
};



class GraphTable{
	//list of stateNotes
	//Space is required between angled brackets
public:
	//Dont forget your copy constructor
	GraphTable();
	int numVert, numEdges;
	Vertex rootVertex;
	std::vector< std::vector<Edge> > adjacencies;
	void InsertEdgeByWeight(Vertex *vertF,Vertex *vertT, char weigh);
	void InsertVert(Vertex *startVert);
	bool NotFound(Vertex *startVert);
	void PrintTable();
};




#endif /* VERTEX_H_ */