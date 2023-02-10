#include <iostream>
using namespace std;
#include <queue>
#include <unordered_map>
#include <vector>
void printDFS(int **edges, int n, bool *visited, int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == start)
            continue;
        if (edges[start][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, visited, i);
        }
    }
}
void printBFS(int **edges, int n, bool *visited, int start)
{
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;
    while (!pendingVertices.empty())
    {
        int currentyVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentyVertex << " ";
        for (int i = 0; i < n; i++)
        {
            if (edges[currentyVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingVertices.push(i);
            }
        }
    }
}
void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, visited, i);
        }
    }
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, visited, i);
        }
    }
}
bool hasPath(int **edges, int n, int start, int end, bool *visited)
{

    if (start == end)
        return true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {

        if (edges[start][i] == 1 && !visited[i])
        {
            visited[i] = true;
            ans = hasPath(edges, n, i, end, visited);
            if (ans == true)
                return true;
        }
    }
    return ans;
}
vector<int> *GetPathDFS(int **edges, int n, int start, int end, bool *visited)
{
    if (start == end)
    {
        vector<int> *temp = new vector<int>;
        temp->push_back(start);
        return temp;
    }
    vector<int> *temp2 = NULL;
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        if (edges[start][i] == 1)
        {
            vector<int> *temp = GetPathDFS(edges, n, i, end, visited);
            if (temp != NULL)
            {
                temp2 = temp;
                break;
            }
        }
    }
    if (temp2 != NULL)
    {
        temp2->push_back(start);
    }
    return temp2;
}
vector<int> *GetPathBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *temp = new vector<int>;
        temp->push_back(sv);
        return temp;
    }
}
vector<int> *GetPathUsingBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    unordered_map<int, int> parent;
    bool done = false;

    while (!pendingVertices.empty() && !done)
    {
        int ans = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[ans][i] == 1 && !visited[i])
            {
                visited[i] = true;
                pendingVertices.push(i);
                parent[i] = ans;
                if (i == ev)
                {
                    done = true;
                    break;
                }
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
        int curr = ev;
        ans->push_back(ev);
        while (curr != sv)
        {
            curr = parent[curr];
            ans->push_back(curr);
        }
        return ans;
    }
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
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int a, b;
    cin >> a >> b;
    vector<int> *ans = GetPathUsingBFS(edges, n, a, b, visited);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << endl;
    }
}