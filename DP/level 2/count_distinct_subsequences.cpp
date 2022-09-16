#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;

	int n = s.size();

	ll dp[n + 1] = {0};
	dp[0] = 1;

	vector <int> v(26, -1);

	for(int i = 1; i <= n; ++i)
	{
		dp[i] = 2ll * dp[i - 1];

		int id = s[i - 1] - 'a';

		if(v[id] != -1)
			dp[i] = dp[i] - dp[v[id]];

		v[id] = i - 1;
	}

	cout << dp[n] - 1 << "\n";
}
