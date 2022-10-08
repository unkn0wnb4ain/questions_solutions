#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	vector <vector <int>> nebs(10);

	nebs[0] = {0, 8};
	nebs[1] = {1, 2, 4};	
	nebs[2] = {1, 2, 3, 5};	
	nebs[3] = {2, 3, 6};	
	nebs[4] = {1, 4, 5, 7};	
	nebs[5] = {2, 5, 8, 4, 6};	
	nebs[6] = {3, 6, 5, 9};	
	nebs[7] = {4, 7, 8};	
	nebs[8] = {0, 5, 8, 7, 9};	
	nebs[9] = {6, 8, 9};

	vector <vector <int>> dp(n + 1, vector <int> (10, 0));

	for (int i = 1; i <= n; ++i)
	{
		for (int num = 0; num < 10; ++num)
		{
			if (i == 1)
				dp[i][num] = 1;

			else
			{
				for (auto ele : nebs[num])
					dp[i][num] += dp[i - 1][ele];
			}
		}
	}	

	ll ans = 0;

	for (int i = 0; i < 10; ++i)
		ans += dp[n][i];

	cout << ans << "\n";
}
