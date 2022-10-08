#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for (auto &i : a) 
		cin >> i;	

	vector <int> dp(n, 0);

	ll ans = 0;

	for (int i = 2; i < n; ++i)
	{
		if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
		{
			dp[i] = dp[i - 1] + 1;
			ans += dp[i];
		}
	}

	cout << ans << "\n";
}
