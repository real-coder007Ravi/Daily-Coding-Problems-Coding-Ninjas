#include <iostream>
#include <queue>
using namespace std;
void printBFS(int **edges, int n, bool *visited, int sv)
{
    queue<int> pendingQueue;
    pendingQueue.push(sv);
    visited[sv] = true;
    while (!pendingQueue.empty())
    {
        int ans = pendingQueue.front();
        pendingQueue.pop();
        cout << ans << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == ans)
                continue;
            if (edges[ans][i] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingQueue.push(i);
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter no of vertices and edges:" << endl;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    printBFS(edges, n, visited, 1);
}