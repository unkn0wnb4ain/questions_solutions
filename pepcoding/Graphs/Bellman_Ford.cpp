#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;		

	vector <array <int, 3>> edges(m);

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edges[i] = {a, b, c};
	}

	vector <int> path(n + 1, INT_MAX);

	path[1] = 0;

	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < m; ++j)
		{
			int a = edges[j][0];
			int b = edges[j][1];
			int c = edges[j][2];

			if(path[a] == INT_MAX)
				continue;

			if(path[a] + c < path[b])
				path[b] = path[a] + c;
		}
	}

	for(int i = 2; i <= n; ++i)
	{
		if(path[i] == INT_MAX)
			cout << 1000000000 << " ";

		else
			cout << path[i] << " ";
	}
}																			
