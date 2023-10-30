#include <stdio.h>

#define MAX_VERTICES 100

// Define a graph structure
typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize a graph with a given number of vertices
void initializeGraph(Graph *graph, int vertices) {
    int i, j;

    graph->vertices = vertices;

    // Initialize the adjacency matrix with zeros
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Add an edge between two vertices in the graph
void addEdge(Graph *graph, int source, int destination) {
    // Assuming a simple, undirected graph
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

// Print the adjacency matrix of the graph
void printGraph(Graph *graph) {
    int i, j;

    printf("Adjacency Matrix:\n");

    for (i = 0; i < graph->vertices; i++) {
        for (j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph myGraph;

    // Initialize a graph with 5 vertices
    initializeGraph(&myGraph, 5);

    // Add edges to the graph
    addEdge(&myGraph, 0, 1);
    addEdge(&myGraph, 0, 3);
    addEdge(&myGraph, 1, 2);
    addEdge(&myGraph, 3, 4);

    // Print the adjacency matrix
    printGraph(&myGraph);

    return 0;
}
