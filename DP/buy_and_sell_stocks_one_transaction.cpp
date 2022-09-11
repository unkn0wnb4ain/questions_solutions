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

	int max_profit = INT_MIN, cur_min = a[0];

	for(int i = 1; i < n; ++i)
	{
		cur_min = min(cur_min, a[i]);
		max_profit = max(max_profit, a[i] - cur_min);
	}

	cout << max_profit << "\n";
}
