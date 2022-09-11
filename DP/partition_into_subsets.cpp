#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	ll n, k;
	cin >> n >> k;

	vector <vector <ll>> dp(n + 1, vector <ll> (k + 1, 0));

	for(ll i = 1; i <= k; ++i)
	{
		for(ll j = 1; j <= n; ++j)
		{
			if(j < i)
				dp[j][i] = 0;

			if(i == j || i == 1 || j == 1)
				dp[j][i] = 1;

			else
				dp[j][i] = dp[j - 1][i] * (i) + dp[j - 1][i - 1];
		}
	}

	cout << dp[n][k] << "\n";
}
