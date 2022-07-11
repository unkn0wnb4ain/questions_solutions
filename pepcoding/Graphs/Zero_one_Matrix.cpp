#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n, vector <int> (m, 0));

    queue <pair <int, int>> q;

    int row = 0, col = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            a[i][j] = (a[i][j] == 0 ? 0 : -1); 

            if(a[i][j] == 0)
            {
                row = i, col = j;
                q.push({i, j});
            }
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    function <void()> bfs;

    bfs = [&]()
    {   
        while(q.size())
        {
            pair <int, int> front = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i)
            {
                int roww = front.first + dx[i];
                int coll = front.second + dy[i];

                if(roww >= 0 && roww < n && coll >= 0 && coll < m && a[roww][coll] < 0)
                {
                    a[roww][coll] = a[front.first][front.second] + 1;
                    q.push({roww, coll});
                }
            }
        }
    };

    bfs();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << " \n"[j == m - 1];

}
