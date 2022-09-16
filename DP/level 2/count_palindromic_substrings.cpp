#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;

	int n = s.size();	

	bool dp[n][n];
	memset(dp, 0, sizeof(dp));

	int cps = 0;

	for(int gap = 0; gap < n; ++gap)
	{
		for(int i = 0, j = gap; j < n; ++i, ++j)
		{
			if(gap == 0)
				dp[i][j] = 1;

			else if(gap == 1)
				dp[i][j] = (s[i] == s[j]);

			else
				if(s[i] == s[j] && dp[i + 1][j - 1])
					dp[i][j] = 1;

			cps += dp[i][j];
		}
	}

	cout << cps << "\n";
}
