#include <string>
#include "Vertex.h"
using namespace std;

Edge::Edge(Vertex *vertT, char weigh){
	weight = weigh;
	vertexTo=vertT;
}

Vertex::Vertex(){
	thisState.stateId= -1;
	thisState.finalState=false;
	thisState.rootState=false;
	out = NULL;
	out2 = NULL;
}

void Edge:: makeFalse(){
	vertexTo->thisState.finalState=false;
}

GraphTable::GraphTable(){
	numVert =0;
	numEdges=0;
	Vertex rootVertex;
}

void GraphTable::InsertVert(Vertex *startVert){
			//adjacencies[startVert->thisState.stateId]=startVert;

}

bool GraphTable::NotFound(Vertex *startVert){
	for(int i;i<adjacencies.size();i++){

	}
	return true;
}

//adjacencies[v][e]
void GraphTable::InsertEdgeByWeight(Vertex *vertF,Vertex *vertT, char weigh){
	//Connecting Edge vertF -----> vertT via weigh
	   Edge tempEdge = Edge(vertT,weigh);
	   //Is this right?
	   //vertF->out = &tempEdge;
	   //This is how I'd want to run this
	  // adjacencies[vertF->thisState.stateId]=vertF;
	   //Mathching stateID to adjacency index [v][e]--[weight]
	   adjacencies[vertF->thisState.stateId].push_back(tempEdge);


}

void GraphTable::PrintTable(){
//	for(int i=0;i<adjacencies.size();i++){
//		//std::cout<< adjacencies[i]<<"State ID and "<< "gs" <<end;
//	}
}
