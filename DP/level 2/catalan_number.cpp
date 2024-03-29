#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	vector <int> dp(n + 1, 0);

	dp[0] = dp[1] = 1;

	for(int i = 2; i <= n; ++i)
		for(int j = 0; j < i; ++j)
			dp[i] += dp[j] * dp[i - j - 1];

	cout << dp[n] << "\n";
}		
