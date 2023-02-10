#include <iostream>
using namespace std;
void printDFS(int **edges, int n, bool *visited, int startvertex)
{
    cout << startvertex << endl;
    visited[startvertex] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == startvertex)
            continue;
        if (edges[startvertex][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, visited, i);
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
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
   
    printDFS(edges, n, visited, 0);
}