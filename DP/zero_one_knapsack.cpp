#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int val[n];
	for(auto &i : val) 
		cin >> i;	

	int weight[n];
	for(auto &i : weight) 
		cin >> i;

	int capacity;
	cin >> capacity;

	vector <vector <int>> dp(n + 1, vector <int> (capacity + 1, 0));

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= capacity; ++j)
		{
			dp[i][j] = dp[i - 1][j];

			if(weight[i - 1] <= j)
				dp[i][j] = max(dp[i][j], val[i - 1] + dp[i - 1][j - weight[i - 1]]);
		}
	}

	cout << dp[n][capacity] << "\n";
}
