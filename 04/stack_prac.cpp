// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing
    // adjacency lists
    vector<int> *adj;
 
    // A recursive function used by DFS
    void DFSUtil(int v, vector<bool> visited);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v, int V);
    
    // Stack version of DFS
    void DFStack(int s, int V);
};
 
Graph::Graph(int V)
{
    //this->V = V;
    adj = new vector<int>[V];
}
 
void Graph::addEdge(int from, int to)
{
    adj[from].push_back(to); // Add from to to’s list.
}
 
void Graph::DFSUtil(int v, vector<bool> visited)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v, int V)
{
    // Mark all the vertices as not visited
    //bool *visited = new bool[V];
    vector<bool> visited;
    for (int i = 0; i < V; i++)
      visited.push_back(false);
 
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

void Graph::DFStack(int s, int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    //bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
      visited.push_back(false);
 
    // Create a queue for BFS
    stack<int> stack;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    stack.push(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    vector<int>::iterator i;
 
    while(!stack.empty())
    {
        // Dequeue a vertex from queue and print it
        s = stack.top();
        cout << s << " ";
        stack.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                stack.push(*i);
            }
        }
    }
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2, 4);
    g.DFStack(2, 4);
 
    return 0;
}