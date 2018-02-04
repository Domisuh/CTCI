// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency
    // lists
    vector<int> *adj;   
    int length;
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w); 
    
    // returns # of nodes in graph
    int getLength();
 
    // prints BFS traversal from a given source s
    bool routeNodes(int s, int j, int V);  
};
 
Graph::Graph(int V)
{
    //this->V = V;
    adj = new vector<int>[V];
    length = V;
}
 
void Graph::addEdge(int from, int to)
{
    adj[from].push_back(to); // Add from to to’s list.
}
 
int Graph::getLength() 
{
  return length;  
}

bool Graph::routeNodes(int n1, int n2, int len)
{
    if (n1 == n2) return true;
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(len, false); // sets all values to false
    //bool *visited = new bool[V];
 
    // Create a queue for BFS
    queue<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[n1] = true;
    queue.push(n1);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    vector<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        n1 = queue.front();
        cout << n1 << " ";
        queue.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[n1].begin(); i != adj[n1].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
                if (*i == n2) return true;
            }
        }
    }
    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.routeNodes(0, 3, g.getLength());
 
    return 0;
}