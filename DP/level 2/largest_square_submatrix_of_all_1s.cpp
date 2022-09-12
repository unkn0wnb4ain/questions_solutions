#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	int a[n][m];
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			cin >> a[i][j];	

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = m - 1; j >= 0; j--)
		{
			if(i == n - 1 || j == m - 1 || a[i][j] == 0)
				continue;

			else
				a[i][j] = min({a[i + 1][j], a[i + 1][j + 1], a[i][j + 1]}) + 1;
		}
	}

	int ans = 0;

	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			ans = max(ans, a[i][j]);

	cout << ans << "\n";
}
