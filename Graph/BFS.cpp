#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &adjList, int startNode, vector<bool> &visited)
{
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Traversing the whole queue
    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        
        vector<int>::iterator it; // declare a iterator
        
        // visiting neighbors
        for (it = adjList[currentNode].begin(); it != adjList[currentNode].end(); it++)
        {
            if (!visited[*it]) // if not visited any neighbor
            {

                visited[*it] = true; // then make it visited

                q.push(*it); // and then push it to the queue

            }
        }

        // or I can write this like that
            /*

            for (int neighbor: adjList[currentNode])
            {
            if (!visited[neighbor])
            {
                        visited[neighbor] = true;
                        q.push(neighbor);
            }
        
            */
    }
}

// Function to add an edge
void addEdge(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    // Number of vertices
    int vertices = 5;

    // Adjacency list representation
    vector<vector<int>> adjList(vertices);

    // Adding edges
    addEdge(adjList, 0, 3);
    addEdge(adjList, 3, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);

    // Marking all the vertices as not visited
    vector<bool> visited(vertices, false);

    // BFS traversal
    bfs(adjList, 0, visited);
}
