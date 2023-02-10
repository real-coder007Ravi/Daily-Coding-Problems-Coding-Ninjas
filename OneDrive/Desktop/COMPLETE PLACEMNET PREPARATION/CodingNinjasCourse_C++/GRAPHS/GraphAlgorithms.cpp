#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>

int findVertex(int *weights, bool *visited, int n)
{
    int ans = -1;
    for (int i = 0; i<n; i++)
    {
        if (!visited[i] && (weights[i] < weights[ans]))
        {
            ans = i;
        }
    }
    return ans;
}
void Prims(int **edges, int n, int e)
{
    int *weights = new int[n];
    bool *visited = new bool[n];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    weights[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int findMinVertex = findVertex(weights, visited, n);
        visited[findMinVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[findMinVertex][j] != 0 && !visited[j] && edges[findMinVertex][j] < weights[j])
            {
                weights[j] = edges[findMinVertex][j];
                parent[j] = findMinVertex;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout <<  parent[i] << " " <<i<<" "<< weights[i] << endl;
        }
        else
        {
            cout << i << " "<<parent[i] << " " << weights[i] << endl;
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
        int s, f, weight;
        cin >> s >> f >> weight;
        edges[s][f] = weight;
        edges[f][s] = weight;
    }
    Prims(edges, n, e);
    cout << endl;
   
}