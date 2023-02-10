#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <climits>
int off[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int bfs(vector<vector<int>> &board, vector<vector<bool>> &visited, int n, int i, int j)
{
    queue<pair<int, int>> pendingqueue;
    pendingqueue.push({i, j});
    int count = 1;
    visited[i][j] = true;
    while (!pendingqueue.empty())
    {
        auto s = pendingqueue.front();
        pendingqueue.pop();
        for (int k = 0; k < 4; k++)
        {
            int row = s.first + off[k][0];
            int col = s.second + off[k][1];
            if (row < n && row >= 0 && col < n && col >= 0 && !visited[row][col] && board[row][col] == 1)
            {
                count++;
                pendingqueue.push({row, col});
                visited[row][col] = true;
            }
        }
    }
    return count;
}
int LargestPieceOfCake(vector<vector<int>> &board, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 && !visited[i][j])
            {
                ans = max(ans, bfs(board, visited, n, i, j));
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << LargestPieceOfCake(board, n) << endl;
}