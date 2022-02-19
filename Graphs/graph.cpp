#include <iostream>
#include <vector>
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
    return 0;
}