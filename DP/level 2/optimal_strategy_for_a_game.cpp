#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	ll n;
	cin >> n;

	ll a[n];
	for(auto &i : a) 
		cin >> i;	

	ll x[n][n];
	memset(x, 0, sizeof(x));

	for(int g = 0; g < n; ++g)
	{
		for(int i = 0, j = g; j < n; ++j, ++i)
		{
			if(g == 0)
				x[i][j] = a[i];

			else if(g == 1)
				x[i][j] = max(a[i], a[j]);

			else
			{
				// i + 1, j
				ll val1 = a[i] + min(x[i + 2][j], x[i + 1][j - 1]);

				// i, j - 1
				ll val2 = a[j] + min(x[i + 1][j - 1], x[i][j - 2]);

				x[i][j] = max(val1, val2);
			}
		}
	}

	cout << x[0][n - 1] << "\n";
}
