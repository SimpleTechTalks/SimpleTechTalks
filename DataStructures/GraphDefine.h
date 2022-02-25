#ifndef _PRACTICE_GRAPH_DEFINE_H_
#define _PRACTICE_GRAPH_DEFINE_H_

#include "QueueDefine.h"
#include "StackDefine.h"
#include "stdio.h"

using namespace std;

class Graph
{
    private:
        int m_nodes;
        int m_edges;
        int **edges;
        bool isUndirected;
        int isConnected;

    public:
        Graph (int nodes, bool isUndirected);
        int getNumberOfNodes ();
        int getNumberOfEdges ();
        void getEdges ();
        bool addEdge (int srcNode, int dstNode);
        bool addEdgeWithWeight (int srcNode, int dstNode, int weight);
        void BFS (int start);
        void DFS (int start);
        ~Graph ();
        bool isConnectedGraph ();
        bool printMotherVertex ();
        void topologicalSort ();
        void getEdgesIn2DFormat ();
        void shortestPathInUnweightedGraph (int srcNode);
        void shortestPathInWeightedGraph (int srcNode);
        void shortestPathInWeightedGraph_dijkstra (int srcNode);
};

Graph::~Graph ()
{
    if (!edges)
    {
        cout << "Graph was never initializaed, nothing to free " << endl;
        return;
    }

    for (int i = 0; i < m_nodes; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}

Graph::Graph (int nodes, bool isUndirected): m_nodes (nodes),
                                             m_edges (0),
                                             edges (NULL),
                                             isUndirected (isUndirected),
                                             isConnected (-1)
{
    edges = new int*[m_nodes];
    
    if (!edges)
    {
        cout << "Graph initialization failed " << endl; 
    }

    for (int i = 0; i < m_nodes; i++)
    {
        edges[i] = new int[m_nodes];
    }

    for (int i = 0; i < m_edges; i++)
    {
        for (int j = 0; j < m_edges; j++)
        {
            edges[i][j] = 0;
        }
    }
}

int Graph::getNumberOfNodes ()
{
    return m_nodes;
}

int Graph::getNumberOfEdges ()
{
    return m_edges;
}

void Graph::getEdges ()
{
    if (!edges)
    {
        cout << "Graph is not initialized properly " << endl; 
    }

    for (int i = 0; i < m_nodes; i++)
    {
        for (int j = 0; j < m_nodes; j++)
        {
            cout << "Node " << i << " and Node " << j << " edge status: " << edges[i][j] << endl;
        }
    }
}

bool Graph::addEdge (int srcNode, int dstNode)
{
    if (srcNode >= m_nodes || dstNode >= m_nodes)
    {
        cout << "srcNode " << srcNode << " or dstNode " << dstNode << " is out of known max node: " << m_nodes << endl;
        return false;
    }

    if (edges[srcNode][dstNode])
    {
        cout << "srcNode " << srcNode << " or dstNode " << dstNode << " is already existed." << endl;
        return false;
    }

    edges[srcNode][dstNode] = 1;
    ++m_edges;
    if (isUndirected)
    {
        edges[dstNode][srcNode] = 1;
        ++m_edges;
    }
    return true;
}

bool Graph::addEdgeWithWeight (int srcNode, int dstNode, int weight)
{
    if (isUndirected) {
        cout << "Weighted graph not defined for undirected graph" << endl;
        return false;
    }
    if (srcNode >= m_nodes || dstNode >= m_nodes)
    {
        cout << "srcNode " << srcNode << " or dstNode " << dstNode << " is out of known max node: " << m_nodes << endl;
        return false;
    }

    if (edges[srcNode][dstNode])
    {
        cout << "srcNode " << srcNode << " or dstNode " << dstNode << " is already existed." << endl;
        return false;
    }

    edges[srcNode][dstNode] = weight;
    ++m_edges;
    return true;
}

void Graph::BFS (int start)
{
    cout << "Starting BFS traversing of Graph from Node: " << start << endl;
    bool visited[m_nodes];
    for (int i = 0; i < m_nodes; i++)
        visited[i] = false;

    if (m_nodes == 0)
    {
        cout << "There is no nodes present in Graph" << endl;
    }

    if (start < 0)
    {
        start = 0;
    }

    if (start >= m_nodes)
    {
        cout << "Graph traversal not possible as start node not found" << endl;
        return;
    }

    Queue q(m_nodes);
    q.enqueue (start);

    while (!q.isEmpty ())
    {
        int visiting = q.dequeue ();

        if (visited[visiting])
        {
            cout << "Graph node " << visiting << " Already visited, skipping!!!" << endl;
            continue;
        }

        visited[visiting] = true;

        cout << "Visited node: " << visiting << " in the Graph." << endl;
        for (int i = 0; i < m_nodes; i++)
        {
            if (edges[visiting][i] && !visited[i])
            {
                cout << "Pushing node " << i << endl;
                q.enqueue (i);
            }
        }
    }
}

void Graph::DFS (int start)
{
    cout << "Starting DFS traversing of Graph from Node: " << start << endl;
    bool visited[m_nodes];
    for (int i = 0; i < m_nodes; i++)
        visited[i] = false;

    if (m_nodes == 0)
    {
        cout << "There is no nodes present in Graph" << endl;
    }

    if (start < 0)
    {
        start = 0;
    }

    if (start >= m_nodes)
    {
        cout << "Graph traversal not possible as start node not found" << endl;
        return;
    }

    Stack s(m_nodes);
    s.push (start);

    while (!s.isEmpty ())
    {
        int visiting = s.pop ();

        if (visited[visiting])
        {
            cout << "Graph node " << visiting << " Already visited, skipping!!!" << endl;
            continue;
        }

        visited[visiting] = true;

        cout << "Visited node: " << visiting << " in the Graph." << endl;
        for (int i = 0; i < m_nodes; i++)
        {
            if (edges[visiting][i] && !visited[i])
            {
                cout << "Pushing node " << i << endl;
                s.push (i);
            }
        }
    }

    /* Below code is to check whether Graph is connected or not */
    isConnected = -1;
    for (int i = 0; i < m_nodes; i++)
    {
        if (!visited[i])
        {
            isConnected = 0;
            break;
        }
    }

    if (isConnected == -1)
    {
        isConnected = 1;
    }
}

bool Graph::isConnectedGraph ()
{
    if (isConnected == -1)
    {
        DFS (0);
    }
    return isConnected;
}

bool Graph::printMotherVertex ()
{
    if (isUndirected)
    {
        if (isConnectedGraph ())
        {
            cout << "Graph is undirected and connected, Hence all nodes are mother vertex." << endl;
            return true;
        }
        else
        {
            cout << "Graph is not connected, no mother vertex possible." << endl;
            return false;
        }
    }
    else
    {
        for (int i = 0; i < m_nodes; i++)
        {
            DFS (i);
            if (isConnected)
            {
                cout << "Graph is directed and connected, mother vertex is: " << i << endl;
                return true;
            }
        }
        cout << "Graph is directed and not connected, mother vertex not possible." << endl;
        return false;
    }
}

void Graph::getEdgesIn2DFormat ()
{
    cout << "Printing edges in 2D format!!" << endl;
    for (int i = 0; i < m_nodes; i++)
    {
        for (int j = 0; j < m_nodes; j++)
        {
            cout << edges[i][j] << "  ";
        }
        cout << endl;
    }
}

void Graph::topologicalSort ()
{
    int indegree[m_nodes];
    for (int i = 0; i < m_nodes; i++)
        indegree[i] = 0;

    for (int i = 0; i < m_nodes; i++)
    {
        for (int j = 0; j < m_nodes; j++)
        {
            if (i == j)
                continue;
            if (edges[i][j])
                indegree[j]++;
        }
    }

    cout << "Printing indegree of nodes" << endl;
    Queue q(m_nodes);
    for (int i = 0; i < m_nodes; i++)
    {
        cout << indegree[i] << "  ";
        if (indegree[i] == 0)
        {
            q.enqueue (i);
        }
    }
    cout << endl;

    cout << "Printing Topological sort !!" << endl;
    int counter = 0;
    while (!q.isEmpty ())
    {
        counter++;
        int node = q.dequeue ();
        cout << node << "  ";

        for (int j = 0; j < m_nodes; j++)
        {
            if (node == j)
                continue;
            if (edges[node][j] == 1)
            {
                if (--indegree[j] == 0)
                    q.enqueue (j);
            }
        }
    }
    cout << endl;
    if (counter != m_nodes)
        cout << "Graph has cycles, topological sort not possible !!" << endl;
}

void Graph::shortestPathInUnweightedGraph (int srcNode)
{
    int distance[m_nodes];
    int path[m_nodes];
    for (int i = 0; i < m_nodes; i++) {
        distance[i] = -1;
        path[i] = -1;
    }

    Queue q(m_nodes);
    q.enqueue (srcNode);
    distance[srcNode] = 0;
    path[srcNode] = srcNode;

    while (!q.isEmpty ()) {
        int cur_node = q.dequeue ();
        if (distance[cur_node] == -1) {
            cout << "Incorrect distance set for node: " << cur_node << endl;
        }
        for (int j = 0; j < m_nodes; j++) {
            if (edges[cur_node][j] == 1 && distance[j] == -1) {
                distance[j] = distance[cur_node] + 1;
                q.enqueue (j);
                path[j] = cur_node;
            }
        }
    }
    for (int i = 0; i < m_nodes; i++) {
        cout <<"Node: " << i << " distance: " << distance[i] << " from Node: " << path[i] << endl;
    }
}

/* Bellman Ford's algorithm */
void Graph::shortestPathInWeightedGraph (int srcNode)
{
    int distance[m_nodes];
    int path[m_nodes];
    for (int i = 0; i < m_nodes; i++) {
        distance[i] = 9999;
        path[i] = 0;
    }

    distance[srcNode] = 0;
    path[srcNode] = srcNode;

    /* The shortest path of graph that contain V vertices, never contain more than "V-1" edges.
       So we do here "V-1" iterations */
    for (int i = 0; i < m_nodes-1; i++) {
        for (int j = i; j < m_nodes; j++) {
            for (int k = 0; k < m_nodes; k++) {
                if (edges[j][k] != 0) {
                    //printf ("%d -- %d -- %d -- %d -- %d -- %d -- %d\n", m_nodes, i, j, k, edges[j][k], distance[j], distance[k]);
                    if (distance[j] != 9999 && distance[k] > distance[j] + edges[j][k]) {
                        distance[k] = distance[j] + edges[j][k];
                        path[k] = j;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m_nodes; i++) {
        bool exit = false;
        for (int j = 0; j < m_nodes; j++) {
            if (edges[i][j] != 0 && distance[j] > distance[i] + edges[i][j]) {
                cout << "Negative edge cycle exists in Graph !!!" << endl;
                exit = true;
                break;
            }
        }
        if (exit)
            break;
    }

    for (int i = 0; i < m_nodes; i++) {
        cout <<"Node: " << i << " distance: " << distance[i] << " from Node: " << path[i] << endl;
    }
}

/* Dijkstra's algorithm */
void Graph::shortestPathInWeightedGraph_dijkstra (int srcNode)
{
    int distance[m_nodes];
    int path[m_nodes];
    bool visited[m_nodes];
    for (int i = 0; i < m_nodes; i++) {
        if (edges[srcNode][i])
            distance[i] = edges[srcNode][i];
        else
            distance[i] = 9999;
        path[i] = srcNode;
        visited[i] = false;
    }

    distance[srcNode] = 0;
    path[srcNode] = srcNode;
    visited[srcNode] = true;
    for (int i = 0; i < m_nodes; i++) {
        if (i == srcNode)
            continue;
        int min_wt = 9999, min_node = 0;
        /* Pickup the node having minimum weight */
        for (int j = 0; j < m_nodes; j++) {
            if (!visited[j]) {
                if (distance[j] < min_wt) {
                    min_wt = distance[j];
                    min_node = j;
                }
            }
        }
        visited[min_node] = true;
        for (int k = 0; k < m_nodes; k++) {
            if (!visited[k] && edges[min_node][k]) {
                if (distance[k] > distance[min_node] + edges[min_node][k]) {
                    distance[k] = distance[min_node] + edges[min_node][k];
                    path[k] = min_node;
                }
            }
        }
    }

    for (int i = 0; i < m_nodes; i++) {
        cout <<"Node: " << i << " distance: " << distance[i] << " from Node: " << path[i] << endl;
    }
}

#endif /* _PRACTICE_GRAPH_DEFINE_H_ */