#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	int a[n][m];
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			cin >> a[i][j];	

	int dp[n][m];
	for(int j = m - 1; j >= 0; j--)
	{
		for(int i = 0; i < n; ++i)
		{
			if(j == m - 1)
        		dp[i][j] = a[i][j];

			else if(i == 0)
				dp[i][j] = max(dp[i + 1][j + 1], dp[i][j + 1]) + a[i][j];

			else if(i == n - 1)
				dp[i][j] = max(dp[i - 1][j + 1], dp[i][j + 1]) + a[i][j];

			else
				dp[i][j] = max({dp[i - 1][j + 1], dp[i][j + 1], dp[i + 1][j + 1]}) + a[i][j];
		}
	}

	int mx = INT_MIN;
	for(int i = 0; i < n; ++i)
		mx = max(mx, dp[i][0]);

	cout << mx << "\n";

	queue <pair <pair <int, int>, string>> q;

	for(int i = 0; i < n; ++i)
		if(dp[i][0] == mx)
			q.push({{i, 0}, to_string(i)});

	while(q.size())
	{
		pair <pair <int, int>, string> mov = q.front();
		q.pop();

		int i = mov.first.first;
		int j = mov.first.second;
		string path = mov.second;

		if(j == m - 1)
			cout << path << "\n";

		else if(i == 0)
		{
			int mxx = max(dp[i][j + 1], dp[i + 1][j + 1]);

			if(dp[i][j + 1] == mxx)
				q.push({{i, j + 1}, path + " d2"});

			if(dp[i + 1][j + 1] == mxx)
				q.push({{i + 1, j + 1}, path + " d3"});
		}

		else if(i == n - 1)
		{
			int mxx = max(dp[i][j + 1], dp[i - 1][j + 1]);

			if(dp[i][j + 1] == mxx)
				q.push({{i, j + 1}, path + " d2"});

			if(dp[i - 1][j + 1] == mxx)
				q.push({{i - 1, j + 1}, path + " d1"});
		}

		else
		{
			int mxx = max({dp[i][j + 1], dp[i + 1][j + 1], dp[i - 1][j + 1]});

			if(dp[i - 1][j + 1] == mxx)
				q.push({{i - 1, j + 1}, path + " d1"});

			if(dp[i][j + 1] == mxx)
				q.push({{i, j + 1}, path + " d2"});

			if(dp[i + 1][j + 1] == mxx)
				q.push({{i + 1, j + 1}, path + " d3"});
		}
	}
}				
