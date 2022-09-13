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

	vector <int> dp(n, 1);

	int lis = 1;

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
			if(a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
			
		lis = max(lis, dp[i]);
	}

	queue <pair <pair <int, int>, string>> q;

	for(int i = 0; i < n; ++i)
	{
		if(lis == dp[i])
			q.push({{lis, i}, to_string(a[i])});
	}

	cout << lis << "\n";

	while(q.size())
	{
		pair <pair <int, int>, string> ele = q.front();
		q.pop();

		int i = ele.first.second;
		int val = ele.first.first;
		string path = ele.second;

		if(val == 1)
			cout << path << "\n";

		for(int j = i - 1; j >= 0; --j)
		{
			if(dp[j] == val - 1 && a[j] <= a[i])
				q.push({{dp[j], j}, to_string(a[j]) + " -> " + path});
		}
	}

}
