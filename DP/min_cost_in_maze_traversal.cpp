#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    ll n, m;
    cin >> n >> m;

    ll grid[n][m];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    vector <vector <ll>> cost(n, vector <ll> (m, INT_MAX));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(i == 0 && j == 0)
                cost[i][j] = grid[i][j];

            else
            {
                if(j)
                    cost[i][j] = min(cost[i][j], grid[i][j] + cost[i][j - 1]);

                if(i)
                    cost[i][j] = min(cost[i][j], grid[i][j] + cost[i - 1][j]);
            }
        }
    }

    cout << cost[n - 1][m - 1] << endl;

}
