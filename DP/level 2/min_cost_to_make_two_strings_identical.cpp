#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	int x;
	cin >> x;

	int y;
	cin >> y;

	int n = a.size();
	int m = b.size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; ++i)	
	{
		for(int j = 1; j <= m; ++j)
		{
			if(a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int lcs = dp[n][m];
	int cost = x * (n - lcs) + y * (m - lcs);

	cout << cost << "\n";
}
