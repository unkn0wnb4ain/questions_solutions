#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ways[100002];

ll recursive_ways(ll n)
{
    if(n == 0)
        return 1;

    if(n < 0)
        return 0;

    if(ways[n] != -1)
        return ways[n];

    ways[n] = recursive_ways(n - 1) + recursive_ways(n - 2) + recursive_ways(n - 3);

    return ways[n];
}

int main()
{

    memset(ways, -1, sizeof(ways));

    ll n;
    cin >> n;

    // cout << recursive_ways(n) << endl;

    ways[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        ways[i] = ways[i - 1];

        if(i > 1)
            ways[i] += ways[i - 2];

        if(i > 2)
            ways[i] += ways[i - 3];
    }

    cout << ways[n] << endl;

}
