#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
// Define a structure for the adjacency list
struct Node {
    int data;
    struct Node* next;
};
// Define a structure for the graph
struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};
struct Graph* createGraph(int nodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = nodes;
    for (int i = 0; i < nodes; i++) {
        graph->adjList[i] = NULL;
    }    return graph;
}// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}
void BFS(struct Graph* graph, int startNode) {
    // Create an array to keep track of visited nodes
    int visited[MAX_NODES] = {0};
    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    // Mark the start node as visited and enqueue it
    visited[startNode] = 1;
    queue[rear++] = startNode;
    printf("Breadth-First Traversal: ");
    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);
        // Traverse the adjacency list and enqueue adjacent nodes
        struct Node* temp = graph->adjList[currentNode];
        while (temp) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                queue[rear++] = adjNode;            }
            temp = temp->next;        }    }
    printf("\n");   }
void DFSRecursive(struct Graph* graph, int currentNode, int visited[]) {
    visited[currentNode] = 1;
    printf("%d ", currentNode);
    struct Node* temp = graph->adjList[currentNode];
    while (temp) {
        int adjNode = temp->data;
        if (!visited[adjNode]) {
            DFSRecursive(graph, adjNode, visited);        }
        temp = temp->next;    }    }
// Function to perform DFS
void DFS(struct Graph* graph, int startNode) {
    int visited[MAX_NODES] = {0};
    printf("Depth-First Traversal: ");
    DFSRecursive(graph, startNode, visited);
    printf("\n");      }  
int main() {
    int nodes, edges, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    struct Graph* graph = createGraph(nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);    }
    int startNode;
    printf("Enter the starting node for traversal: ");
    scanf("%d", &startNode);
    BFS(graph, startNode);
    DFS(graph, startNode);
 return 0;
}