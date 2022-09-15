#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for(auto &i : a) 
		cin >> i;	

	vector <vector <int>> dp(n, vector <int> (n, 0));

	for(int gap = 0; gap < n; ++gap)
	{
		for(int i = 0, j = gap; j < n; ++i, ++j)
		{
			for(int k = i; k <= j; ++k)
			{
				int left = (k == i ? 0 : dp[i][k - 1]);
				int right = (k == j ? 0 : dp[k + 1][j]);
				int val = (i == 0 ? 1 : a[i - 1]) * a[k] * (j == n - 1 ? 1 : a[j + 1]);

				dp[i][j] = max(dp[i][j], left + right + val);
			}
		}
	}

	cout << dp[0][n - 1] << "\n";
}
