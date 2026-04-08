#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

// DFS function
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

// Function to detect cycle
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}

int main() {
    int m, u, v;

    // Input: number of vertices and edges
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges (directed)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
