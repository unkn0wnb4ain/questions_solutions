#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	ll n;
	cin >> n;

	ll space = 1; 
	ll building = 1; 

	for(int i = 2; i <= n; ++i)
	{
		ll btemp = space;
		ll stemp = space + building;

		space = stemp;
		building = btemp;
	}

	cout << (space + building) * (space + building) << "\n";
}
