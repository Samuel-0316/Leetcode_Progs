/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int parent[1001];

int find(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = 2;
    for (int i = 0; i <= 1000; i++) {
        parent[i] = -1;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = find(edges[i][0]);
        int v = find(edges[i][1]);
        if (u == v) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = edges[i][0];
            result[1] = edges[i][1];
            return result;
        }
        parent[u] = v;
    }

    return NULL;
}