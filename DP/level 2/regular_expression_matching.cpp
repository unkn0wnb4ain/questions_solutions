#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string a;
	cin >> a;

	string b;
	cin >> b;

	int n = b.size();
	int m = a.size();

	bool dp[n + 1][m + 1];
	memset(dp, false, sizeof(dp));

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			if(i == 0 && j == 0)
				dp[i][j] = 1;

			else if(i == 0)
				dp[i][j] = 0;

			else if(j == 0)
			{
				if(b[i - 1] == '*')
					dp[i][j] = dp[i - 2][j];

				else
					dp[i][j] = 0;
			}

			else
			{
				char c = b[i - 1];
				char d = a[j - 1];

				if(c == '.')
					dp[i][j] = dp[i - 1][j - 1];

				else if(c == '*')
				{
					dp[i][j] = dp[i - 2][j];

					if(b[i - 2] == d || b[i - 2] == '.')
						dp[i][j] |= dp[i][j - 1];
				}

				else
					if(c == d)
						dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	if(dp[n][m])
		cout << "true\n";

	else
		cout << "false\n";
}		
