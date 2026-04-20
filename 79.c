#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minDist() {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int source;
    scanf("%d", &source);

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = minDist();
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
