#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;

	int n = s.size();	

	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	for(int gap = 0; gap < n; ++gap)
	{
		for(int i = 0, j = gap; j < n; ++i, ++j)
		{
			if(gap == 0)
				dp[i][j] = 1;

			else if(gap == 1)
				dp[i][j] = 2 + (s[i] == s[j]);

			else
				if(s[i] == s[j])
					dp[i][j] = 1 + dp[i][j - 1] + dp[i + 1][j];

				else
					dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
		}
	}

	cout << dp[0][n - 1] << "\n";
}
