#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	vector <int> a(n);
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

	ll sum = accumulate(a.begin(), a.end(), 0ll);

	int k;
	cin >> k;

	if(k == 1)
		cout << best << "\n";

	else
	{
		for(int i = 0; i < n; ++i)
			a.push_back(a[i]);

		curr = 0;
		ll bestt = INT_MIN;

		for(int i = 0; i < 2 * n; ++i)
		{
			curr += a[i];
			bestt = max(bestt, curr);

			curr = (curr < 0 ? 0 : curr);
		}

		if(sum < 0)
			cout << bestt << "\n";

		else
			cout << bestt + (k - 2) * sum << "\n";
	}
}
