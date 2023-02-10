#include <iostream>
using namespace std;
#include <vector>
int isSolve(int **edges, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1 && i != j)
            {
                for (int k = 0; k < n; k++)
                {
                    if (edges[j][k] == 1 && edges[i][k] == 1 && j != i && k != i)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count / 6;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << isSolve(edges, n) << endl;
}