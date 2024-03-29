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

	memset(dp, 0, sizeof(dp));

	int lcss = 0;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = 0;

			lcss = max(lcss, dp[i][j]);
		}
	}

	cout << lcss << "\n";
}
