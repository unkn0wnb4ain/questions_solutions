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

    vector <vector <ll>> max_gold(n + 1, vector <ll> (m, 0));

    for(int i = 0; i < n; ++i)
        max_gold[i][0] = grid[i][0];

    for(int i = 1; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            max_gold[j][i] = max_gold[j][i - 1];

            if(j > 0)
                max_gold[j][i] = max(max_gold[j][i], max_gold[j - 1][i - 1]);

            if(j < n - 1)
                max_gold[j][i] = max(max_gold[j][i], max_gold[j + 1][i - 1]);

            max_gold[j][i] += grid[j][i];
        }
    }

    ll gold = 0;

    for(int i = 0; i < n; ++i)
        gold = max(gold, max_gold[i][m - 1]);

    cout << gold << endl;

}
