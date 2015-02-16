//============================================================================
// Name        : RegDFA.cpp
// Author      : Deverick Simpson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>  // requires standard library
#include <fstream>  // Note this extra header requirement whenever working with files
#include <cstdlib>
using namespace std;

/*stateStatus[0]--a,stateStatus[1]---b,stateStatus[3]--e
 * stateId refers to the current state
 * Struct will represent a state node within the NFA'
 */
struct nfaStruct{
	int stateId;
	char stateStatus[3];
	bool finalState;
};

/*
 * We will rock socks with a reg expression stack to
 * parse tree the reg expression.
 *
 */
stack<int>parsingTree;

void emptyEdge(){

}

void concatEdge(){

}

void kleeneEdge(){

}

void orEdge(){

}

void parser(){
	string STRING;
	    ifstream infile;
	    int b=0;
	    string previousLine="";
	    infile.open ("/Users/Deverick/Documents/workspace/RegDFA/Libs/input.txt");

	    while(!infile.eof()) // To get you all the lines.
	    {
	        getline(infile,STRING); // Saves the line in STRING.
	        //Parsing RegEx
	        if(b==0){
	        	/* Optimization may need to be adjusted for cse.unl.edu
	        	 */


	        	for(std::string::iterator it = STRING.end(); it != STRING.begin(); --it) {
	        	    cout<<"HERE IS THE REVERSE"<<*it<<endl;
	        	}

	        	/*
	        	for(char& c : STRING) {
	        		cout<< "Here is the char: "<< c << endl;

	        	}
	        	*/


	        	cout<<"First String is the REGEX, building table"<<endl;
	        }else{
	        //Testing String Input against cases


	        }
	        cout<<STRING<<endl; // Prints our STRING.
	        b++;
	    }
	    infile.close();
	    cout<<"We are here"<<endl;
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
		   parser();
	   }
	   cout<< "Closing Down"<< endl;
	return 0;

}