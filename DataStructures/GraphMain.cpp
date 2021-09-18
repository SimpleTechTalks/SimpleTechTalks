#include <iostream>

using namespace std;
#include "GraphDefine.h"

void add_header (const char *line)
{
    cout << "========================================================================" << endl;
    cout << line << endl;
    cout << "========================================================================" << endl;
}

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
    add_header ("Printing Edges information in Adjecency Matrix Format.");
    g.getEdgesIn2DFormat ();
    add_header ("Printing BFS traversal of Graph");
    g.BFS (4);
    add_header ("Printing DFS traversal of Graph");
    g.DFS (0);
    add_header ("Checking Graph Connected Status");
    cout << "Graph connected status: " << g.isConnectedGraph () << endl;
    add_header ("Checking Graph Mother Vertex Information");
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
    add_header ("Printing Edges information in Adjecency Matrix Format.");
    g1.getEdges ();
    add_header ("Printing BFS traversal of Graph");
    g1.BFS (0);
    add_header ("Printing DFS traversal of Graph");
    g1.DFS (0);
    add_header ("Checking Graph Connected Status");
    cout << "Graph connected status: " << g1.isConnectedGraph () << endl;
    add_header ("Checking Graph Mother Vertex Information");
    g1.printMotherVertex ();
    add_header ("Sorting Graph Using Topological Sort");
    Graph g2(11, false);
    g2.addEdge (0,4);
    g2.addEdge (1,0);
    g2.addEdge (6,1);
    g2.addEdge (1,2);
    g2.addEdge (1,5);
    g2.addEdge (2,3);
    g2.addEdge (6,3);
    g2.addEdge (3,7);
    g2.addEdge (4,8);
    g2.addEdge (5,8);
    g2.addEdge (9,7);
    g2.addEdge (8,9);
    g2.addEdge (9,10);
    g2.getEdgesIn2DFormat ();
    g2.topologicalSort ();
}
