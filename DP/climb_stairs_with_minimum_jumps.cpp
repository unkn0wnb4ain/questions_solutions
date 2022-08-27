#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    ll n;
    cin >> n;

    ll a[n];

    for(auto &i : a)
        cin >> i;    

    vector <ll> ways(n + 1, -1);

    function <ll(ll)> dp = [&](ll ind)
    {
        if(ind == n)
            return ways[ind] = 0;

        if(ind > n || a[ind] == 0)
            return (ll)1e10;

        if(ways[ind] != -1)
            return ways[ind];

        ways[ind] = 1e10;

        for(int j = 1; j <= a[ind] && ind + j <= n; ++j)
            ways[ind] = min(ways[ind], 1 + dp(ind + j));

        return ways[ind];
    };

    if(dp(0) > INT_MAX)
        cout << "null
";

    else
        cout << dp(0) << endl;

}
