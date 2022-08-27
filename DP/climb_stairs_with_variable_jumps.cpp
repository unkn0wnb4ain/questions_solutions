#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n;
    cin >> n;

    int a[n];

    for(auto &i : a)
        cin >> i;    

    vector <int> ways(n + 1, -1);

    function <int(int)> dp;

    dp = [&](int x)
    {
        if(x == n)
            return ways[x] = 1;

        if(x > n)
            return 0;

        if(ways[x] != -1)
            return ways[x];

        int res = 0;

        for(int j = 1; j <= a[x] && x + j <= n; ++j)
        {
            res += dp(x + j);
        }

        return ways[x] = res;
    };

    cout << dp(0) << endl;

}
