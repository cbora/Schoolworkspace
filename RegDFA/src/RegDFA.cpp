//============================================================================
// Name        : RegDFA.cpp
// Author      : Deverick Simpson
// Version     :
// Copyright   : Your copyright notice
// Description : Reg To DFA in C++, Ansi-style
//============================================================================
#include "InfixToPostfix.h"
#include <iostream>
#include <stack>
#include <utility> //std::pair
#include <map>
#include <string>
#include <vector>
#include <sstream>  // requires standard library
#include <fstream>  // Note this extra header requirement whenever working with files
#include <cstdlib>
#include "Vertex.h"
#include <set>
using namespace std;

//I really dont want this to be global
int id =-1;
char empty = '#';

//
//struct nfaFrag{
//	//points to start state for frag
//	State *start;
//};

Vertex* createStart(){
	   //StartingVertex
	   Vertex* startVertex=NULL;
	   startVertex->thisState.stateId=++id;
	   startVertex->thisState.rootState=true;
	   return startVertex;
}

Vertex* createFinal(){
   //EndingVertex
   Vertex* endVertex=NULL;
   endVertex->thisState.stateId=++id;
   endVertex->thisState.finalState=true;
}
/*
 *
 * Thompsons Construction Algorithm
 * http://swtch.com/~rsc/regexp/regexp1.html
 * -------------------------------------------------------------------------------------
 */
void toNFA(string Postfix){
	GraphTable gTable;


	//Root Node and the ID of the finalState
	std::stack<  std::pair<Vertex,Vertex> > stateHistory;
	//WILL NEED TO CHANGE FOR CSE STANDARDS!!

	for(char& c : Postfix) {
		   switch ( c ) {
		   	   case 'a':{
		   		   //Vertex Construction
		   		   Vertex* rootNode = createStart();
		   		   Vertex* endNode = createFinal();
		   		   Edge tempEdge = Edge(endNode,c);
		   		   *rootNode->out = tempEdge;

		   		   //Save State on stack for Operator
		   		   template<class Vertex, class Vertex>
		   		   class pair{
		   		   public:
		   			   Vertex first;
		   			   Vertex second;
		   			   pair(Vertex first, Vertex second)
		   		   };

		   		    std::pair<Vertex,Vertex> newPair = std::make_pair(rootNode,endNode);
		   		    stateHistory.push(newPair);

		   		   //Figure out your table schema
		   		   //startVertex->thisState  and startVertex->out
		   		   gTable.InsertEdgeByWeight(rootNode,endNode,c);
		   		   gTable.numVert += 2;
		   		   gTable.numEdges++;
		   		 break;
		   	   }
		   	   case 'b':{
		   		   Vertex* rootNode1 = createStart();
		   		   Vertex* endNode1 = createFinal();
		   		   Edge tempEdge = Edge(endNode1,c);
		   		   *rootNode1->out = tempEdge;

		   		   std::pair<Vertex,Vertex> newPair = std::make_pair(rootNode1,endNode1);
		   		   stateHistory.push(newPair);

		   		   //Inserting Into Table
		   		   gTable.InsertEdgeByWeight(rootNode1,endNode1,c);
		   		   gTable.numVert += 2;
		   	       gTable.numEdges++;
		   		 break;
		   	   }
		   	   case '*':{

		   		 break;
		   	   }
		   	   case '|':{
		   		   Vertex* rootNode2 = createStart();
		   		   Vertex* endNode2 = createFinal();

		   		   Vertex* nodeA =  &stateHistory.top();
		   		   stateHistory.pop();

		   	   	   Vertex* nodeB = &stateHistory.top();
		   	       stateHistory.pop();


		   	       Edge firstEdge = Edge(nodeA,empty);
		   	       Edge secondEdge = Edge(nodeB,empty);
		   	       //rootNode2->out = &firstEdge; diff between *rootNode2->out = firstEdge;

		   	       //New Root node attached
		   	       rootNode2->thisState.stateId = ++id;
		   	       rootNode2->out = &firstEdge;
		   	       rootNode2->out2 = &secondEdge;

		   	       //Remove old root and final state markers
		   	       nodeA->thisState.rootState=false;
		   	       nodeB->thisState.rootState=false;

		   	       //Final state False
		   	       //Also need to save index on this swap
		   	       nodeA->out->makeFalse();
		   	       //Prob dont need  these
		   	       nodeA->out2->makeFalse();

		   	       nodeB->out->makeFalse();
		   	       //Prob dont need  these
		   	       nodeB->out2->makeFalse();

		   	       //Add new Final Node
		   	       //Maintain consistent stateId
		   	       endNode2->thisState.stateId = ++id;
		   	       Edge finalEdge = Edge(endNode2,empty);
		   	       Edge finalEdge1 = Edge(endNode2,empty);

		   	       nodeA->out = &finalEdge;
		   	       nodeB->out = &finalEdge;

		   	       stateHistory.push(*rootNode2);
		   	       //Add to Graph Table
		   	      gTable.InsertEdgeByWeight(rootNode2,nodeA,empty);
		   	      gTable.InsertEdgeByWeight(rootNode2,nodeB,empty);
		   	      gTable.InsertEdgeByWeight(nodeA,endNode2,empty);
		   	      gTable.InsertEdgeByWeight(nodeB,endNode2,empty);
		   		 break;
		   	   }
		   	   case '.':{
		   		   Vertex* nodeA =  &stateHistory.top();
		   		   stateHistory.pop();

		   	   	   Vertex* nodeB = &stateHistory.top();
		   	       stateHistory.pop();

		   	     //  nodeB->out =
		   		 break;
		   	   }
		   	   default:{
		   		 break;
		   	   }
		  }
	}
}

/*
 * File Parsing and Main Function Call
 * ----------------------------------------------------------------------------------
 */

void fileparser(){
	string STRING;
	    ifstream infile;
	    int bIndex=0;
	    string previousLine="";
	   //Change to match homework readme
	    infile.open ("/Users/Deverick/Documents/workspace/RegDFA/Libs/input.txt");

	    while(!infile.eof()) // To get you all the lines.
	    {
	        getline(infile,STRING); // Saves the line in STRING.
	        //Parsing RegEx
	        if(bIndex==0){
	        	//Calling InfixToPostfix File returning a queue
	        	InfixToPostfix sampleTest;
	        	//converToPostfix is a string===remove string creation, wasting space
	        	string postfix = sampleTest.convertToPostfix(sampleTest.addConcat(STRING));
	        	int lengthOF = postfix.size();
	        	cout <<"Here is the postfix expression "<< postfix << endl;
	        	//toNFA(postfix);

	        }
	        //ONE EXTRA TEST CASE IS BEING RAN~~REMOVE--I added 1 to check on bIndex..check that
	        //Testing String Input against cases
	        //cout<<"The test case is: "<<endl;
	        if(bIndex>1){
	        	// cout<<STRING<<endl; // Prints our STRING.
	        }

	        bIndex++;
	    }
	    infile.close();
	    cout<<"We are here "<<endl;
	    //Need to return a parsing stack to manipulate the regex to a NFA
}





int main(){
	char Name[30];
	cout << "!!!Hello, what is your name!!!" << endl; // prints !!!Hello World!!!
	cin >> Name;
	ifstream ifs( "/Users/Deverick/Documents/workspace/RegDFA/Libs/input.txt" );       // note no mode needed
	   if ( ! ifs.is_open() ) {
		   cout << "Hello,"<< Name << " we have failed to open the file, check the path"<< endl;
	   }
	   else {
		   cout << "Hello, "<< Name <<" All seems to be running smooth...Here's the parsing of the file"<< endl;
		   fileparser();
	   }
	   cout<< "Closing Down"<< endl;
	return 0;
}
