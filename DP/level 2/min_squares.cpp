#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	vector <int> dp(n + 1, 0);	

	iota(dp.begin(), dp.end(), 0);

	for(int i = 2; i <= n; ++i)
		for(int j = 1; j * j <= i; ++j)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[n] << "\n";
}
