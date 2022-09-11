#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	vector <int> dp(n + 1, 0);

	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; ++i)	
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n] << "\n";
}
