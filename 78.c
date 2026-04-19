#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int minKey(int n) {
    int min = INT_MAX, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    int u, v, w;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // initialize arrays
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(n);
        visited[u] = 1;

        totalWeight += key[u];

        // update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
