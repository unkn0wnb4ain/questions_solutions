#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, k;
	cin >> n >> k;

	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; ++i)	
	{
		for(int j = 1; j <= k; ++j)
		{
			if(j == 1)
				dp[i][j] = 1;

			else if(i == 1)
				dp[i][j] = j;

			else
			{
				dp[i][j] = INT_MAX;
				int mx = INT_MIN;

				for(int f = 1; f <= j; ++f)
				{
					mx = 1 + max(dp[i - 1][f - 1], dp[i][j - f]);
					dp[i][j] = min(dp[i][j], mx);
				}
			}
		}
	}

	cout << dp[n][k] << "\n";
}		
