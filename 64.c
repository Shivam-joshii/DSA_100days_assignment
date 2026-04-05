#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// Structure for adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int x = queue[front];
    if (front == rear) front = rear = -1;
    else front++;
    return x;
}

int isEmpty() {
    return front == -1;
}

// BFS function
void BFS(struct Node* adj[], int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                enqueue(temp->data);
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        // For undirected graph (optional)
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);

    BFS(adj, s);

    return 0;
}
