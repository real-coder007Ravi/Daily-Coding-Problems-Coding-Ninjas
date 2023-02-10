#include <iostream>
using namespace std;
#include <climits>
int findvertex(int *distance, bool *visited, int n)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && distance[i] < distance[ans])
        {
            ans = i;
        }
    }
    return ans;
}
void DijkstraAlgorithms(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int i = 0; i < n-1; i++)
    {
        int vertexmin = findvertex(distance, visited, n);
        visited[vertexmin] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[vertexmin][j] != 0&&!visited[j])
            {
                int dist = distance[vertexmin] + edges[vertexmin][j];
                if (distance[j] > dist)
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}
int main()
{
    int n, e;
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
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[s][f] = weight;
        edges[f][s] = weight;
    }
    cout << "Output of Dijkstra's Algorithm" << endl;
    DijkstraAlgorithms(edges, n);
}