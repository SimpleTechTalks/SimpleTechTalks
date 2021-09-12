#include "QueueDefine.h"
#include "StackDefine.h"

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
        void BFS (int start);
        void DFS (int start);
        ~Graph ();
        bool isConnectedGraph ();
        bool printMotherVertex ();
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

void Graph::BFS (int start)
{
    cout << "Starting BFS traversing of Graph from Node: " << start << endl;
    bool visited[m_nodes] = {false};

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
    bool visited[m_nodes] = {false};

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
