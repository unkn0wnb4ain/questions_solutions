#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <vector <int>> ancestor;

void DestroyInSeconds()
{
    int n;
    cin >> n;

    vector <int> p(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    ancestor.assign(17, vector <int> (n + 1, 0));

    for (int i = 0; i < n; ++i) 
        ancestor[0][i] = p[i];

    for (int i = 1; i < 17; ++i)
        for (int j = 0; j < n; ++j)
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];

    int q;
    cin >> q;
    while (q-- > 0)
    {
        int node, k;
        cin >> node >> k;

        for (int i = 0; i < 17; ++i)
            if ((k >> i) & 1)
                node = ancestor[i][node];

        cout << node << "\n";
    }
}    

int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 

    while (testcases-- > 0)
        DestroyInSeconds();
}
    
