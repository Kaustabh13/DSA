#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief This function is used to add edges
 * 
 * @param adj -> The adjacency list 
 * @param u -> The first vetrice value
 * @param v -> The second service value
 */

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * @brief This function is used to print the graph
 * 
 * @param adj -> The adjacency list
 * @param V -> The total number of nodes
 */

void printGraph(vector<int> adj[], int V) {

    for(int i = 0; i < V; i++) {
       cout << "Adjacency List of vertex " << i << endl;
       cout << "head";
       for(int j = 0; j < adj[i].size(); j++) {
           cout << " -> " << adj[i][j]; 
       }

       cout << endl;
    }
}

/**
 * @brief This function is used to add the adjacency matrix
 * 
 * @param mat -> The adjacency matrix
 * @param u -> The first node
 * @param v -> The second node
 */

void addMatrixEdge(vector< vector<int> > &mat, int u, int v) {
    mat[u][v] = 1;
    mat[v][u] = 1;
}

/**
 * @brief This function is used to print the matrix
 * 
 * @param mat -> The adjacency matrix
 * @param V -> The count of vertices
 */

void printMatrix(vector< vector<int> > mat, int V) {

    for(int i = 0; i < V; i++) {

        for(int j = 0; j < mat[i].size(); j++) {
            cout << " " << mat[i][j] << " ";
        }

        cout << endl;    
    }
}

//Traversal

/**
 * @brief This function is used to find the BFS of a graph
 * 
 * @param adj -> The adjacency list
 * @param V -> The count of vertices
 */

void bfs(vector<int> adj[], int V) {

    vector<int> stored;
    vector<int> visited(V,0);

    queue<int> q;
    q.push(0); //Assuming 0 as the starting point of the graph, if changed add an argument in the function int position
    visited[0] = 1;

    //Wrap it in a for loop if there are multiple components
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        stored.push_back(node);

        for(int it: adj[node]) {
             if(!visited[it]) {
                 q.push(it);
                 visited[it] = 1;
             }
        }
    }
    
    cout << "BFS for Graph is -> " << endl;

    for(int i = 0; i < stored.size(); i++) {
        cout << stored[i] << " ";
    }

    cout << endl;
}

/**
 * @brief This function is used to store the values in the vector
 * 
 * @param node -> The vertice/node
 * @param visited -> List of booleans telling whether a node at an index is visited or not
 * @param adj -> The adjacency list
 * @param stored -> The stored values
 */

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &stored) {
    stored.push_back(node);
    visited[node] = 1;

    for(int it: adj[node]) {
        if(!visited[it]) {
            dfs(it, visited, adj, stored); //Recursion
        }
    }
}

/**
 * @brief This function is used to find out the DFS of a graph
 * 
 * @param adj -> The adjacency matrix
 * @param V -> The count of vertices
 */

void dfsOfGraph(vector<int> adj[], int V) {

    vector<int> stored;
    vector<int> visited(V,0);

    if(!visited[0]) {
        dfs(0, visited, adj, stored);
    }

    cout << "DFS for Graph is -> " << endl;

    for(int i = 0; i < stored.size(); i++) {
        cout << stored[i] << " ";
    }

    cout << endl;
} 

//Graph
// [[0,1],[0,4],[1,2],[1,3],[1,4],[2,3],[3,4]]

int main() {

    int V = 5; //Vertices Count

    //Adjacency List
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);

    //Adjacency Matrix
    vector< vector<int> > mat(V, vector<int>(V,0));
    cout << "Pre Add" << endl;
    printMatrix(mat, V);

    addMatrixEdge(mat, 0, 1);
    addMatrixEdge(mat, 0, 4);
    addMatrixEdge(mat, 1, 2);
    addMatrixEdge(mat, 1, 3);
    addMatrixEdge(mat, 1, 4);
    addMatrixEdge(mat, 2, 3);
    addMatrixEdge(mat, 3, 4);

    cout << "Post Add" << endl;

    printMatrix(mat, V);

    cout << endl;

    bfs(adj, V);

    cout << endl;

    dfsOfGraph(adj, V);
    return 0;
}