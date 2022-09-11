#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for(int &i : a)	
		cin >> i;

	int mn = a[0], mx = a[n - 1];

	vector <int> pre(n, 0);
	vector <int> suf(n, 0);

	pre[0] = 0;
	suf[n - 1] = 0;

	for(int i = 1; i < n; ++i)
	{
		mn = min(mn, a[i]);
		pre[i] = max(pre[i - 1], a[i] - mn);
	}

	for(int i = n - 2; i >= 0; i--)
	{
		mx = max(mx, a[i]);
		suf[i] = max(suf[i + 1], mx - a[i]);
	}

	int max_profit = INT_MIN;

	for(int i = 0; i < n; ++i)
		max_profit = max(max_profit, pre[i] + suf[i]);

	cout << max_profit << "\n";
}
