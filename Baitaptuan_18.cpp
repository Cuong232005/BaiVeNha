#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adjMatrix[MAX][MAX];
int visited[MAX];

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdgeList(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void addEdgeMatrix(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void initGraph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
        adjList[i] = NULL;
        visited[i] = 0;
    }
}

void printAdjList(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        printf("%d: ", i);
        Node* temp = adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void printAdjMatrix(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    Node* temp = adjList[vertex];

    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            dfs(connectedVertex);
        }
        temp = temp->next;
    }
}

void bfs(int startVertex, int vertices) {
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp) {
            int connectedVertex = temp->vertex;
            if (!visited[connectedVertex]) {
                queue[rear++] = connectedVertex;
                visited[connectedVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices = 11;

    initGraph();

    addEdgeMatrix(1, 2); // D6
    addEdgeMatrix(1, 3); // D7
    addEdgeMatrix(1, 4); // D8
    addEdgeMatrix(4, 5); // D9
    addEdgeMatrix(5, 6); // D10
    addEdgeMatrix(6, 4); // D11
    addEdgeMatrix(6, 7); // D12
    addEdgeMatrix(7, 8); // D13
    addEdgeMatrix(8, 9); // D2
    addEdgeMatrix(8, 1); // D1
    addEdgeMatrix(9, 10); // D3
    addEdgeMatrix(10, 1); // D4
    addEdgeMatrix(1, 11); // D5

    addEdgeList(1, 2); // D6
    addEdgeList(1, 3); // D7
    addEdgeList(1, 4); // D8
    addEdgeList(4, 5); // D9
    addEdgeList(5, 6); // D10
    addEdgeList(6, 4); // D11
    addEdgeList(6, 7); // D12
    addEdgeList(7, 8); // D13
    addEdgeList(8, 9); // D2
    addEdgeList(8, 1); // D1
    addEdgeList(9, 10); // D3
    addEdgeList(10, 1); // D4
    addEdgeList(1, 11); // D5

    printf("Ma tran lan can:\n");
    printAdjMatrix(vertices);

    printf("\nDanh sach lan can:\n");
    printAdjList(vertices);

    printf("\nDuyet DFS: ");
    for (int i = 1; i <= vertices; i++) visited[i] = 0;
    dfs(1);

    printf("\nDuyet BFS: ");
    for (int i = 1; i <= vertices; i++) visited[i] = 0;
    bfs(1, vertices);

    return 0;
}
