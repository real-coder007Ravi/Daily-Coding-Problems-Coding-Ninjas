#include <iostream>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
vector<int> *GetPathUsingDFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *ans = new vector<int>;
        ans->push_back(sv);
        return ans;
    }
    vector<int> *temp2 = NULL;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            vector<int> *temp = GetPathUsingDFS(edges, n, i, ev, visited);
            if (temp != NULL)
            {
                temp2 = temp;
                break;
            }
        }
    }
    if (temp2 != NULL)
    {
        temp2->push_back(sv);
    }
    return temp2;
}
vector<int> *GetPathUsingBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(sv);
        return ans;
    }
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    bool done = false;
    unordered_map<int, int> parent;
    while (!pendingVertices.empty() && !done)
    {
        int curr = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[curr][i] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingVertices.push(i);
                parent[i] = curr;
                if (i == ev)
                {
                    done = true;
                    break;
                }
            }
        }
        if (!done)
        {
            return NULL;
        }
        else
        {
            vector<int> *ans = new vector<int>();
            ans->push_back(sv);
            int current = ev;
            while (current != sv)
            {
                current = parent[current];
                ans->push_back(current);
            }
            return ans;
        }
    }
}
void DFS(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited);
        }
    }
}
bool isConnected(int **edges, int n, int sv)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    DFS(edges, n, sv, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}
void DFS(int **edges, int n, int sv, bool *visited, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited, ans);
        }
    }
}
void AllConnectedComponents(int **edges, int n, int sv, bool *visited)
{
    vector<int> ans;
    DFS(edges, n, sv, visited, ans);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int n, e;
    cout << "Enter no of vertices and edges" << endl;
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

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            AllConnectedComponents(edges, n, i, visited);
        }
    }
}