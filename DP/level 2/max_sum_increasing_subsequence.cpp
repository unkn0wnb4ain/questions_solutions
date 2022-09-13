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

	vector <int> dp(n, 0);

	for(int i = 0; i < n; ++i)
		dp[i] = a[i];

	for(int i = 1; i < n; ++i)
	{
		int mx = 0;
		for(int j = 0; j < i; ++j)
			if(a[j] <= a[i])
				mx = max(mx, dp[j]);

		dp[i] += mx;
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
}
