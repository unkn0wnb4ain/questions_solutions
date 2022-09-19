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

	int ele;
	cin >> ele;

	int r = 0, c = m - 1;

	while(r < n && c >= 0)
	{
		if(a[r][c] == ele)
		{
			cout << "true\n";
			return 0;
		}

		if(a[r][c] < ele)
			r++;

		else
			c--;
	}

	cout << "false\n";
}
