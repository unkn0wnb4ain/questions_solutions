#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector <int> graph[n];

	for(int i = 0; i < m; ++i)	
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int timer = 0;
	int bridges = 0;

	int tim[n] = {0};
	int low[n] = {0};

	vector <bool> vis(n, false);

	vector <pair <int, int>> edges;

	function <void(int, int)> dfs;

	dfs = [&](int v, int par)
	{
		vis[v] = true;
		tim[v] = low[v] = timer++;

		for(auto child : graph[v])
		{
			if(child == par)
				continue;

			if(vis[child])
				low[v] = min(low[v], tim[child]);

			else 
			{
				dfs(child, v);

				low[v] = min(low[v], low[child]);

				// '>=' in case of articulation point but only '>' in case of bridge
				if(low[child] > tim[v])
					edges.push_back({v, child});
			}
		}
	};

	dfs(0, -1);

	int ct = 0;
	cout << "[";
	for(auto edge : edges)
	{
		if(ct)
			cout << ", ";

		cout << "[" << edge.first << ", " << edge.second << "]";
		ct++;
	}
	cout << "]";
}
