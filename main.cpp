#include <iostream>
#include <fstream>
#include "GraphList.h"
using namespace std;

int main(){
    string filename = "graph_1.txt";
    ifstream inputFile(filename);
    
    int numVertices;
    inputFile >> numVertices;

    cout << "There are  " <<  numVertices <<" vertices in the Graph" << endl;
    cout << "\n\n";

    GraphList graph(numVertices);
    int startVertext, endvertext;

    while(inputFile >> startVertext >> endvertext){
        graph.addEdge(startVertext,  endvertext);
    }

    inputFile.close();

    graph.printAdjacencyList();
    
}