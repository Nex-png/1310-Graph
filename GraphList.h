#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include<fstream>
#include <iostream>
using namespace std;

class GraphList
{
	private:
		// TODO: build node struct and add class variables
		
	public:
        // TODO: Constructor

        // TODO: Destructor

		// TODO: addEdge

        // TODO: print graph to screen

        // TODO: CHANGE VARIABLE NAMES TO MATCH WHAT YOU MADE THEM.
        // OR COMMENT THIS OUT IF YOU DON'T CARE ABOUT GraphViz

        // Creates output that fits into GraphViz (graph visualization tool). 
		void toGraphViz() { 
			ListNode* nodePtr; 
			ofstream graphOut("digraph.txt"); 

			graphOut<<"digraph {" << endl; 

			for(int i=0; i<numVertices; i++) {

				bool atleastone = false;
				nodePtr = headArray[i];
				graphOut << i;

				while(nodePtr != NULL)
				{
					graphOut << "->" << nodePtr->value << endl;
					nodePtr = nodePtr->next;
					atleastone = true;
					if(nodePtr != NULL)
						graphOut << i; 
				}

				if(!atleastone) { 
					graphOut << "\n";
				}
			}

			graphOut <<"\n}";
			graphOut.close();

		}

};

#endif