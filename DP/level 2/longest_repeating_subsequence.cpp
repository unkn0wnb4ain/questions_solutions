#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;

	int n = s.size();

	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; ++i)	
	{
		for(int j = 1; j <= n; ++j)
		{
			if(s[i - 1] == s[j - 1] && i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n][n] << "\n";
}
