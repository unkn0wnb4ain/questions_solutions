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

	int target;
	cin >> target;

	vector <vector <bool>> dp(n + 1, vector <bool> (target + 1, false));

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= target; j++)
		{
			if(i == 0)
				dp[i][j] = false;

			if(j == 0)
				dp[i][j] = true;

			if(i != 0 && j != 0)
			{
				dp[i][j] = dp[i - 1][j];

				if(a[i - 1] <= j && dp[i - 1][j - a[i - 1]])
					dp[i][j] = true;
			}
		}
	}

	if(dp[n][target])
		cout << "true\n";

	else
		cout << "false\n";
}
