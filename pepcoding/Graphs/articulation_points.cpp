#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector <int> graph[n + 1];

	for(int i = 0; i < m; ++i)	
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int timer = 0;

	int tim[n + 1] = {0};
	int low[n + 1] = {0};

	vector <bool> vis(n + 1, false);
	vector <bool> arti_point(n + 1, false);

	function <void(int, int)> dfs;

	dfs = [&](int v, int par = -1)
	{
		vis[v] = true;
		tim[v] = low[v] = timer++;

		int children = 0;

		for(auto child : graph[v])
		{
			if(child == par)
				continue;

			else if(vis[child])
				low[v] = min(low[v], tim[child]);

			else
			{
				dfs(child, v);
				low[v] = min(low[v], low[child]);

				if(low[child] >= tim[v] && par != -1)
					arti_point[v] = true;

				children++;
			}
		}

		if(children > 1 && par == -1)
			arti_point[v] = true;
	};

	int cut_points = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			dfs(i, -1);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(arti_point[i])
			cut_points++;
	}

	cout << cut_points << "\n";
}
