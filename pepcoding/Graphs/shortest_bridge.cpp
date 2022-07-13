#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n;
    cin >> n;

    vector <vector <int>> a(n, vector <int> (n, 0));

    int row = 0, col = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> a[i][j];

            if(a[i][j])
                row = i, 
                col = j;    
        }
    }

    queue <pair <int, int>> q;

    vector <vector <bool>> vis(n, vector <bool> (n, 0));

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    function <void(int, int)> dfs;

    dfs = [&](int row, int col)
    {
        vis[row][col] = 1;

        q.push({row, col});

        for(int i = 0; i < 4; ++i)
        {
            int roww = row + dx[i];
            int coll = col + dy[i];

            if(roww < 0 || coll < 0 || roww >= n || coll >= n || a[roww][coll] == 0 || vis[roww][coll])
                continue;

            dfs(roww, coll);
        }
    };

    dfs(row, col);

    int flips = 0;

    function <void()> bfs;

    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                pair <int, int> front = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i)
                {
                    int roww = front.first + dx[i];
                    int coll = front.second + dy[i];

                    if(roww < 0 || coll < 0 || roww >= n || coll >= n || vis[roww][coll])
                        continue;

                    if(a[roww][coll])
                        return;

                    q.push({roww, coll});
                }
            }            
            flips++;
        }
    };

    bfs();

    cout << flips << endl;

}

