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

	ll curr = 0;
	ll best = INT_MIN;

	for(int i = 0; i < n; ++i)
	{
		curr += a[i];
		best = max(best, curr);

		curr = (curr < 0 ? 0 : curr);
	}

	cout << best << "\n";
}
