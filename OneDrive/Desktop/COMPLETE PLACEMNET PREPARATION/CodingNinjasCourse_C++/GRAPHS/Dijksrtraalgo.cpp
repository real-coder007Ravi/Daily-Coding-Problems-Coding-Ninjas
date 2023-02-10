#include <iostream>
#include <climits>
using namespace std;
int findvertex(int *distance, bool *visited, int n)
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (distance[i] < distance[ans]))
        {
            ans = i;
        }
    }
    return ans;
}
void dijkstra(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int i = 0; i < n-1; i++)
    {
        int vertex = findvertex(distance, visited, n);
        visited[vertex] = true;
        for (int j = 0; j < n; j++)
        {
            if(edges[vertex][j]!=0&&!visited[j]){
            int dist = distance[vertex] + edges[vertex][j];
            if (dist < distance[j])
            {
                distance[j] = dist;
            }
        }
        }}
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] <<endl;
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
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    dijkstra(edges, n);
}