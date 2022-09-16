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

	for(int i = n; i >= 0; i--)
	{
		for(int j = m; j >= 0; j--)
		{
			if(i == n && j == m)
				dp[i][j] = true;

			else if(i == n)
				dp[i][j] = false;

			else if(j == m)
			{
				if(b[i] == '*')
					dp[i][j] = dp[i + 1][j];

				else
					dp[i][j] = false;
			}

			else
			{
				if(b[i] == '?')
					dp[i][j] = dp[i + 1][j + 1];

				else if(b[i] == '*')
					dp[i][j] = dp[i + 1][j] | dp[i][j + 1];

				else
				{
					if(b[i] == a[j])
						dp[i][j] = dp[i + 1][j + 1];

					else
						dp[i][j] = false;
				}
			}
		}
	}
	
	if(dp[0][0])
		cout << "true\n";

	else
		cout << "false\n";

}			
