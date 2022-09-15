#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n; 
	cin >> n;

	vector <int> a(n + 1, 0);
	for(int i = 0; i < n; ++i)	
		cin >> a[i + 1];

	vector <int> dp = a;

	for(int i = 2; i <= n; ++i)
	{
		int l = 1, r = i - 1;

		while(l <= r)
			dp[i] = max(dp[i], dp[l++] + dp[r--]);
	}

	cout << dp[n] << "\n";
}
