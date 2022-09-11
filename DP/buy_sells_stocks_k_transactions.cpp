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

	int k;
	cin >> k;

	vector <vector <int>> dp(k + 1, vector <int> (n, 0));

	for(int i = 1; i <= k; ++i)
	{
		int mx = INT_MIN;
		for(int j = 1; j < n; ++j)
		{
			mx = max(mx, dp[i - 1][j - 1] - a[j - 1]);
			dp[i][j] = max(mx + a[j], dp[i][j - 1]);
		}
	}

	cout << dp[k][n - 1] << "\n";
}
