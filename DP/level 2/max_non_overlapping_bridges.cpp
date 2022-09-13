#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	pair <int, int> a[n];
	for(auto &i : a)	
		cin >> i.first >> i.second;

	sort(a, a + n);

	vector <int> dp(n, 1);

	for(int i = 1; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(a[j].second <= a[i].second)
				dp[i] = max(dp[i], dp[j] + 1);

	cout << *max_element(dp.begin(), dp.end()) << "\n";
}
