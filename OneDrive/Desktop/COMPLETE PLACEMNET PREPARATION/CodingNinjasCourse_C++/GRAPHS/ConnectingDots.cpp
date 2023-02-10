#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, int fromX, int fromY, char color, int n, int m, bool &IsCycle)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return ;
    if (board[i][j] != color)
        return ;
    if (visited[i][j])
    {
        IsCycle = true;
        return;
    }
    visited[i][j] = true;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int m = 0; m < 4; m++)
    {
        int nextX = i + dx[m];
        int nextY = j + dy[m];
        if (nextX == fromX && nextY == fromY)
            continue;
        dfs(board, visited, nextX, nextY, fromX, fromY, color, n, m, IsCycle);
    }
}
bool ConnectedDots(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool IsCycle = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(board, visited, i, j, -1, -1, board[i][j], n, m, IsCycle);
            }
        }
    }
    return IsCycle;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << ConnectedDots(board, n, m) << endl;
}