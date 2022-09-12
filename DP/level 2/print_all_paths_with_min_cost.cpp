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

	vector <vector <int>> dp(n, vector <int> (m, 0));

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(i == n - 1 && j == m - 1)
				dp[i][j] = a[i][j];

			else if(i == n - 1)
				dp[i][j] = dp[i][j + 1] + a[i][j];

			else if(j == m - 1)
				dp[i][j] = dp[i + 1][j] + a[i][j];

			else
				dp[i][j] = a[i][j] + min({dp[i + 1][j], dp[i][j + 1]});
		}
	}

	cout << dp[0][0] << "\n";

	queue <pair <pair <int, int>, string>> q;
	q.push({{0, 0}, ""});

	while(q.size())
	{
		pair <pair <int, int>, string> mov = q.front();
		q.pop();

		int i = mov.first.first;	
		int j = mov.first.second;	
		string path = mov.second;

		if(i == n - 1 && j == m - 1)
			cout << path << "\n";

		else if(i == n - 1)
			q.push({{i, j + 1}, path + "H"});

		else if(j == m - 1)
			q.push({{i + 1, j}, path + "V"});

		else
		{
			if(dp[i + 1][j] == dp[i][j + 1])
			{
				q.push({{i + 1, j}, path + "V"});
				q.push({{i, j + 1}, path + "H"});
			}	

			else if(dp[i + 1][j] < dp[i][j + 1])
				q.push({{i + 1, j}, path + "V"});

			else
				q.push({{i, j + 1}, path + "H"});
		}
	}
}
