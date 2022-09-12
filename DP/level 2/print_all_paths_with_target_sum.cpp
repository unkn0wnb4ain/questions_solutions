#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for(int  &i : a)
		cin >> i;

	int tar;
	cin >> tar;

	bool dp[n + 1][tar + 1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= n; ++i)	
	{
		for(int j = 0; j <= tar; ++j)
		{
			if(j == 0)
				dp[i][j] = 1;

			else if(i == 0)
				dp[i][j] = 0;

			else
			{
				dp[i][j] = dp[i - 1][j];

				if(j >= a[i - 1])
					dp[i][j] |= dp[i - 1][j - a[i - 1]];
			}
		}
	}

	if(dp[n][tar])
	{
		cout << "true\n";

		queue <pair <pair <int, int>, string>> q;
		q.push({{n, tar}, ""});

		while(q.size())
		{
			pair <pair <int, int>, string> mov = q.front();
			q.pop();

			int i = mov.first.first;
			int j = mov.first.second;
			string path = mov.second;

			if(i == 0 || j == 0)
				cout << path << "\n";

			else
			{
				if(j >= a[i - 1])
				{
					int inc = dp[i - 1][j - a[i - 1]];
					if(inc)
						q.push({{i - 1, j - a[i - 1]}, to_string(i - 1) + " " + path});
				}

				int exc = dp[i - 1][j];
				if(exc)
					q.push({{i - 1, j}, path});
			}
		}
	}

	else
		cout << "false\n";
}
