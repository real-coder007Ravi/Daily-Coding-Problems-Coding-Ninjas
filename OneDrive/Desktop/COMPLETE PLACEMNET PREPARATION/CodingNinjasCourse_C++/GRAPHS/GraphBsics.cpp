#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        cout << current << " ";
        for (int i = 0; i < n; i++)
        {
            if (edges[current][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
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
void printDFS(int **edges, int n)
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
            DFS(edges, n, i, visited);
        }
    }
}
void printBFS(int **edges, int n)
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
            BFS(edges, n, i, visited);
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
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}
bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    DFS(edges, n, 0, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}
void PushIntoEdges(int **edges, int n, int sv, bool *visited, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {

            PushIntoEdges(edges, n, i, visited, ans);
        }
    }
}
void GetAllConnectedComponents(int **edges, int n, int sv, bool *visited)
{
    vector<int> ans;
    PushIntoEdges(edges, n, sv, visited, ans);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
vector<int> *GetPathUsingDFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *temp = new vector<int>;
        temp->push_back(sv);
        return temp;
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
vector<int> *GetPathUisngBFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
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
                parent[i] = curr;
                visited[i] = true;
                pendingVertices.push(i);
                if (i == ev)
                {
                    done = true;
                    break;
                }
            }
        }
    }

    if (!done)
        return NULL;
    else
    {
        vector<int> *temp = new vector<int>();
        int current = ev;
        temp->push_back(ev);
        while (current != sv)
        {
            current = parent[current];
            temp->push_back(current);
        }
        return temp;
    }
}
int CountofConnectComponents(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(edges, n, i, visited);
            ans++;
        }
    }
    return ans;
}
bool isFound(vector<vector<char>> &board, int TotalRows, int TotalCols, int CurrentRow, int currentCol, vector<vector<bool>> &visited, string s)
{
    if (s.size() == 0)
        return true;
    visited[CurrentRow][currentCol] = true;
    bool ans = false;
    // Down
    if (CurrentRow + 1 < TotalRows && !visited[CurrentRow + 1][currentCol] && board[CurrentRow + 1][currentCol] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow + 1, currentCol, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Up
    if (CurrentRow - 1 >= 0 && !visited[CurrentRow - 1][currentCol] && board[CurrentRow - 1][currentCol] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow - 1, currentCol, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Left
    if (currentCol - 1 >= 0 && !visited[CurrentRow][currentCol - 1] && board[CurrentRow][currentCol - 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow, currentCol - 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Right
    if (currentCol + 1 < TotalCols && !visited[CurrentRow][currentCol + 1] && board[CurrentRow][currentCol + 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow, currentCol + 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Up Left
    if (CurrentRow - 1 >= 0 && currentCol - 1 >= 0 & !visited[CurrentRow - 1][currentCol - 1] && board[CurrentRow - 1][currentCol - 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow - 1, currentCol - 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Up Right
    if (CurrentRow - 1 >= 0 && currentCol + 1 < TotalCols && !visited[CurrentRow - 1][currentCol + 1] && board[CurrentRow - 1][currentCol + 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow - 1, currentCol + 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Down Left
    if (CurrentRow + 1 < TotalRows && currentCol - 1 >= 0 && !visited[CurrentRow + 1][currentCol - 1] && board[CurrentRow + 1][currentCol - 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow + 1, currentCol - 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    // Down Right
    if (CurrentRow + 1 < TotalRows && currentCol + 1 < TotalCols && !visited[CurrentRow + 1][currentCol + 1] && board[CurrentRow + 1][currentCol + 1] == s[0])
    {
        if (isFound(board, TotalRows, TotalCols, CurrentRow + 1, currentCol + 1, visited, s.substr(1)))
        {
            return true;
        }
    }
    visited[CurrentRow][currentCol] = false;
    return ans;
}
bool isFound(vector<vector<char>> &board, int TotalRows, int TotalColumns)
{
    vector<vector<bool>> visited(TotalRows, vector<bool>(TotalColumns, false));
    for (int i = 0; i < TotalRows; i++)
    {
        for (int j = 0; j < TotalColumns; j++)
        {
            if (board[i][j] == 'C')
            {
                string s = "ODINGNINJAS";
                if (isFound(board, TotalRows, TotalColumns, i, j, visited, s))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
#include<bits/stdc++.h>
bool bfs( vector< vector<char> > &board , int n , int m ,int ci , int cj,vector< vector<bool> >&visited,string s)
{
    if(s.size()==0)
    {
        return true;
    }
    visited[ci][cj]=true;


    bool ans = false;
    if(ci+1<n && !visited[ci+1][cj] && board[ci+1][cj]==s[0])// down
    {
        if( bfs(board,n,m,ci+1,cj,visited, s.substr(1)))
            return true;
    }

    if(ci-1>=0 && !visited[ci-1][cj] && board[ci-1][cj]==s[0])// up

    {
        if(  	bfs(board,n,m,ci-1,cj,visited, s.substr(1)))
            return true;
    }
    if(cj-1>=0 && !visited[ci][cj-1] && board[ci][cj-1]==s[0])// left
    {
        if( bfs(board,n,m,ci,cj-1,visited, s.substr(1)))
            return true;
    }

    if(cj+1<m && !visited[ci][cj+1] && board[ci][cj+1]==s[0])// right
    {
        if( bfs(board,n,m,ci,cj+1,visited, s.substr(1)))
            return true;
    }


    if(ci+1<n && cj-1>=0&&!visited[ci+1][cj-1] && board[ci+1][cj-1]==s[0])// down left
    {
        if( bfs(board,n,m,ci+1,cj-1,visited, s.substr(1)))
            return true;
    }

    if(ci+1<n && cj+1<m&&!visited[ci+1][cj+1] && board[ci+1][cj+1]==s[0])// down right
    {
        if( bfs(board,n,m,ci+1,cj+1,visited, s.substr(1)))
            return true;
    }


    if(ci-1>=0 && cj-1>=0 && !visited[ci-1][cj-1] && board[ci-1][cj-1]==s[0])// up left 
    {
        if( bfs(board,n,m,ci-1,cj-1,visited, s.substr(1)))
            return true;
    }

    if(ci-1>=0 && cj+1<m&& !visited[ci-1][cj+1] && board[ci-1][cj+1]==s[0])// up right
    {
        if(	 bfs(board,n,m,ci-1,cj+1,visited, s.substr(1)))
            return true;
    }
    
 visited[ci][cj]=false;

    return ans;
}




 bool hasPath(vector<vector<char>> &board, int n, int m) {
     vector<vector<bool> >visited(n,vector<bool>(m, false));
       for(int i=0; i<n ; i++)
         {    for(int j=0 ; j< m; j++)
                  {
                    if(board[i][j]=='C')
                    {

                        string s ="ODINGNINJA";

                        if(bfs(board, n,m,i,j,visited,s))
                            return true;

                    }
                }
                }
                return false;

            } 


int main()
{
    int TotalRows, TotalCols;
    cin >> TotalRows >> TotalCols;
    vector<vector<char>> board(TotalRows, vector<char>(TotalCols));
    for (int i = 0; i < TotalRows; i++)
    {
        for (int j = 0; j < TotalCols; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << hasPath(board, TotalRows, TotalCols) << endl;
}