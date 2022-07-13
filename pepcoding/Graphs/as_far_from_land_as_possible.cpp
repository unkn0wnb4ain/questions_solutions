#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n;
    cin >> n;

    vector <vector <int>> a(n, vector <int> (n, 0));

    queue <pair <int, int>> q;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> a[i][j];

            if(a[i][j])
                q.push({i, j});
        }
    }

    if(q.size() == n * n || q.size() == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int level = -1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    function <void()> bfs;

    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();
            level++;

            while(size--)
            {
                pair <int, int> front = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i)
                {
                    int row = front.first + dx[i];
                    int col = front.second + dy[i];

                    if(row < 0 || col < 0 || row >= n || col >= n || a[row][col] == 1)
                        continue;

                    a[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
    };

    bfs();

    cout << level << endl;

}

