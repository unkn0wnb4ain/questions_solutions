#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector <pair <int, int>> graph[n + 1];

	for(int i = 1; i <= n; ++i)		
	{
		int x;
		cin >> x;
		graph[0].push_back({i, x});
		graph[i].push_back({0, x});
	}

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	int cost = 0;

	vector <bool> vis(n + 1, false);		

	priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

	pq.push({0, 0});

	while(pq.size())
	{
		pair <int, int> node = pq.top();
		pq.pop();

		if(vis[node.first])
			continue;

		vis[node.first] = true;

		cost += node.second;

		for(auto child : graph[node.first])
		{
			if(vis[child.first] == false)
			{
				pq.push({child});
			}
		}
	}

	cout << cost << "\n";
}
