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

	int w[n];
	for(auto &i : w) 
		cin >> i;	

	int cap;
	cin >> cap;

	int dp[n + 1][cap + 1];

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= cap; ++j)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;

			else
			{
				dp[i][j] = dp[i - 1][j];

				if(j >= w[i - 1])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
			}
		}
	}

	cout << dp[n][cap] << "\n";

	queue <pair <pair <int, int>, string>> q;
	q.push({{n, cap}, ""});

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
			int exc = dp[i - 1][j];
			if(exc == dp[i][j])
				q.push({{i - 1, j}, path});

			if(j >= w[i - 1])
			{
				int inc = dp[i - 1][j - w[i - 1]] + val[i - 1];
				if(inc == dp[i][j])
					q.push({{i - 1, j - w[i - 1]}, to_string(i - 1) + " " + path});
			}
		}
	}
}
