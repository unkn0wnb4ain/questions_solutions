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

	int buy_id = 0;
	int sel_id = 0;
	int max_profit = 0;

	for(int i = 1; i < n; ++i)
	{
		if(a[i] < a[i - 1])
		{
			max_profit += a[sel_id] - a[buy_id];
			sel_id = buy_id = i;
		}

		else
			sel_id++;
	}

	max_profit += a[sel_id] - a[buy_id];

	cout << max_profit << "\n";
}
