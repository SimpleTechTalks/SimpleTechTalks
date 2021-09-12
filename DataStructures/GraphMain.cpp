#include <iostream>

using namespace std;
#include "GraphDefine.h"

int main ()
{
    Graph g(5, true);
    g.addEdge (1,2);
    g.addEdge (0,2);
    g.addEdge (3,2);
    g.addEdge (4,2);
    g.addEdge (1,3);
    g.addEdge (1,4);
    g.addEdge (1,5);
    g.addEdge (1,7);
    g.addEdge (1,0);
    g.addEdge (2,2);
    g.addEdge (3,2);
    g.addEdge (4,2);
    g.addEdge (5,2);
    cout << "Graph has nodes: " << g.getNumberOfNodes () << endl;
    cout << "Graph has edges: " << g.getNumberOfEdges () << endl;
//    g.getEdges ();
    g.BFS (4);
    g.DFS (0);
    cout << "Graph connected status: " << g.isConnectedGraph () << endl;
    g.printMotherVertex ();

    Graph g1(5, false);
    g1.addEdge (1,2);
    g1.addEdge (0,2);
    g1.addEdge (3,2);
    g1.addEdge (4,2);
    g1.addEdge (1,3);
    g1.addEdge (1,4);
    g1.addEdge (1,5);
    g1.addEdge (1,7);
    g1.addEdge (1,0);
    g1.addEdge (2,2);
    g1.addEdge (3,2);
    g1.addEdge (4,1);
    g1.addEdge (5,2);
    cout << "Graph has nodes: " << g1.getNumberOfNodes () << endl;
    cout << "Graph has edges: " << g1.getNumberOfEdges () << endl;
    g1.getEdges ();
    g1.BFS (0);
    g1.DFS (0);
    cout << "Graph connected status: " << g1.isConnectedGraph () << endl;
    g1.printMotherVertex ();
}
