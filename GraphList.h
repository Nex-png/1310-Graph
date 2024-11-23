#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include<fstream>
#include <iostream>
using namespace std;

class GraphList
{
	private:
		// TODO: build node struct and add class variables
		struct ListNode
		{
			int value;
			ListNode *next;
			
		};
		ListNode** headArray;
		int numOfVertices;
		int numOfEdges;

		
		
	public:
        // TODO: Constructor
		GraphList(int Vertices){
			numOfVertices = Vertices;
			numOfEdges = 0;
			headArray = new ListNode*[Vertices];
			for(int i = 0; i < Vertices; i++){
				headArray[i] = nullptr;
			}
		

		}
        // TODO: Destructor
		~GraphList(){

		}

		// TODO: addEdge
		void addEdge(int index, int value){
			
		}


        // TODO: print graph to screen

        // TODO: CHANGE VARIABLE NAMES TO MATCH WHAT YOU MADE THEM.
        // OR COMMENT THIS OUT IF YOU DON'T CARE ABOUT GraphViz

        // Creates output that fits into GraphViz (graph visualization tool). 
		void toGraphViz() { 
			ListNode* nodePtr; 
			ofstream graphOut("digraph.txt"); 

			graphOut<<"digraph {" << endl; 

			for(int i=0; i<numOfVertices; i++) {

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