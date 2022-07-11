#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n, vector <int> (m, 0));

    queue <pair <int, int>> q;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> a[i][j];

            if(a[i][j] == 2)
                q.push({i, j});
        }
    }

    int time = -1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    function <void()> bfs;

    bfs = [&]()
    {   
        queue <pair <int, int>> child;

        while(q.size())
        {
            pair <int, int> front = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i)
            {
                int roww = front.first + dx[i];
                int coll = front.second + dy[i];

                if(roww >= 0 && roww < n && coll >= 0 && coll < m && a[roww][coll] == 1)
                {
                    a[roww][coll] = 2;
                    child.push({roww, coll});
                }
            }

            if(q.empty())
            {
                q = child;
                child = queue <pair <int, int>> () ;
                time++;
            }
        } 
    };

    bfs();

    bool ok = 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ok &= (a[i][j] != 1);
        }
    }

    cout << (ok ? time : -1) << "\n";

}
