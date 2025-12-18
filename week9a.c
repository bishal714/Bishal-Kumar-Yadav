#include <stdio.h>

int main() {
    int n, i, j, start;
    int graph[10][10], visited[10] = {0}, queue[10];
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
