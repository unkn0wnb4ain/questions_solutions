#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector <int> dp(n + 1, 0);

	for(int i = 1; i < min(n + 1, m); ++i)
		dp[i] = 1;

	if(m <= n)
		dp[m] = 2;

	for(int i = m + 1; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - m];

	cout << dp[n] << "\n";
}
