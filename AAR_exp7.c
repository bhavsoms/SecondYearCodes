#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

int graph[V][V] = {
    { 0, 10, 15, 20 },
    { 10, 0, 35, 25 },
    { 15, 35, 0, 30 },
    { 20, 25, 30, 0 }
};

int visited[V], min_cost = INT_MAX;

void tsp(int curr_city, int count, int cost) {
    if (count == V && graph[curr_city][0]) {
        cost += graph[curr_city][0];
        if (cost < min_cost)
            min_cost = cost;
        return;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[curr_city][i]) {
            visited[i] = 1;
            tsp(i, count+1, cost+graph[curr_city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    visited[0] = 1;
    tsp(0, 1, 0);
    printf("Minimum cost: %d\n", min_cost);
    return 0;
}
