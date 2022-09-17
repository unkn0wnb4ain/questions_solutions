#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	int n = a.size();
	int m = b.size();

	int dp[n + 1][m + 1];

	for(int i = 0; i <= n; ++i)	
	{
		for(int j = 0; j <= m; ++j)
		{
			if(i == 0 && j == 0)
				dp[i][j] = 0;

			else if(i == 0)
				dp[i][j] = j;

			else if(j == 0)
				dp[i][j] = i;

			else
			{
				if(a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1];

				else
				{
					int insert = dp[i][j - 1];
					int remove = dp[i - 1][j];
					int replace = dp[i - 1][j - 1];

					dp[i][j] = 1 + min({insert, remove, replace});
				}
			}
		}
	}

	cout << dp[n][m] << "\n";
}
