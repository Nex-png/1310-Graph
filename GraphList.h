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
			ListNode(int nodeValue){
				value = nodeValue;
				next = NULL;
			}
			
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
			for(int i = 0; i < numOfVertices; i++){
				ListNode* current = headArray[i];
				while(current != nullptr){
					ListNode* temp = current;
					current = current->next;
					delete temp;
				}
			}

			delete[] headArray;

		}


			
		// tripped me up at first as I was at first adding the edges at the front rather than the back.
		void addEdge(int index, int value){
			ListNode* newNode = new ListNode(value);
			
			if(headArray[index] == nullptr){
				headArray[index] = newNode;
			}
			else{
				ListNode* current = headArray[index];
				while(current->next != nullptr){
					current = current->next;
				}
				current->next = newNode;
			}
			numOfEdges++;
			cout << "Added edge from " << index << " to " << value << endl;
		}


        // TODO: print graph to screen
		void printAdjacencyList(){
			cout << "\n\nAdjacency List..." << endl;
			for(int i = 0; i < numOfVertices; i++){
				cout << i << "--->";
				ListNode* current = headArray[i];
				while(current != nullptr){
					cout << current->value << "--->";
					current = current->next;
				}
				cout << "NULL" << endl; 
			}
		}

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

				while(nodePtr != nullptr)
				{
					graphOut << "->" << nodePtr->value << endl;
					nodePtr = nodePtr->next;
					atleastone = true;
					if(nodePtr != nullptr)
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