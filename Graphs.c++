#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define TABLE_SIZE 11

// --- Graph Representation --- //
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int queue[MAX_NODES], front = 0, rear = 0;
int nodes, edges;

void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1; // Undirected graph
}

void bfs(int start)
{
    for (int i = 0; i < nodes; i++)
        visited[i] = false;

    front = rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < nodes; i++)
        {
            if (graph[node][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void dfs(int node)
{
    if (visited[node])
        return;

    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < nodes; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

// --- Modified Hashing Part --- //

typedef struct
{
    int value1;
    int value2;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i].value1 = -1;
        hashTable[i].value2 = -1;
    }
}

void insert(int key)
{
    int index = key % TABLE_SIZE;
    int originalIndex = index;

    while (hashTable[index].value1 != -1 && hashTable[index].value2 != -1)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
        {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    if (hashTable[index].value1 == -1)
        hashTable[index].value1 = key;
    else
        hashTable[index].value2 = key;

    printf("Inserted: %d at index %d\n", key, index);
}

void displayHashTable()
{
    printf("Index | Value1 | Value2\n");
    printf("------------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf(" %4d |  %5d |  %5d\n", i,
               hashTable[i].value1 == -1 ? -1 : hashTable[i].value1,
               hashTable[i].value2 == -1 ? -1 : hashTable[i].value2);
    }
}

// --- Main Program --- //

int main()
{
    int choice, u, v, start, key, numKeys;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Graph Operations (BFS & DFS)\n");
        printf("2. Hashing Operations (Insert & Display)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &nodes);
            printf("Enter number of edges: ");
            scanf("%d", &edges);

            // Clear graph
            for (int i = 0; i < MAX_NODES; i++)
                for (int j = 0; j < MAX_NODES; j++)
                    graph[i][j] = 0;

            for (int i = 0; i < edges; i++)
            {
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                addEdge(u, v);
            }

            printf("Enter start node for BFS: ");
            scanf("%d", &start);
            printf("BFS Traversal: ");
            bfs(start);

            for (int i = 0; i < nodes; i++)
                visited[i] = false;

            printf("Enter start node for DFS: ");
            scanf("%d", &start);
            printf("DFS Traversal: ");
            dfs(start);
            printf("\n");
            break;

        case 2:
            initHashTable();
            printf("Enter number of keys to insert: ");
            scanf("%d", &numKeys);

            for (int i = 0; i < numKeys; i++)
            {
                printf("Enter key %d: ", i + 1);
                scanf("%d", &key);
                insert(key);
            }

            printf("\nHash Table:\n");
            displayHashTable();
            break;

        case 3:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
