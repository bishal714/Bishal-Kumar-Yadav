#include <stdio.h>

int graph[10][10], visited[10];
int n;

/* DFS function */
void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            visited[i] = 0;
        }
    }

    /* Start DFS from vertex 0 */
    dfs(start);

    /* Check if all vertices are visited */
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is CONNECTED\n");
    return 0;
}


