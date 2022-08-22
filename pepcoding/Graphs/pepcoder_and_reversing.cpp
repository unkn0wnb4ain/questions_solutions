#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	ll n, m;
	cin >> n >> m;

	vector <pair <ll, ll>> graph[n + 1];

	for(int i = 0; i < m; ++i)	
	{
		ll x, y;
		cin >> x >> y;

		graph[x].push_back({y, 0});
		graph[y].push_back({x, 1});
	}

	vector <bool> vis(n + 1, false);

	deque <pair <ll, ll>> q;

	q.push_back({1, 0});

	while(q.size())
	{
		pair <ll, ll> p = q.front();
		q.pop_front();

		vis[p.first] = 1;

		if(p.first == n)
		{
			cout << p.second << "\n";
			return 0;
		}

		for(auto child : graph[p.first])
		{
			if(vis[child.first] == 0)
			{
				if(child.second == 0)
					q.push_front({child.first, p.second + 0});

				else
					q.push_back({child.first, p.second + 1});
			}
		}
	}

	cout << -1 << "\n";

}
