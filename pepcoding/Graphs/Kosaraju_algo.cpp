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
	}

	vector <bool> vis(n + 1, false);

	stack <int> st;

	function <void(int)> dfs1;

	dfs1 = [&](int node)
	{
		vis[node] = true;

		for(auto child : graph[node])
		{
			if(vis[child] == false)
				dfs1(child);
		}

		st.push(node);
	};

	for(int i = 1; i <= n; ++i)
	{
		if(vis[i] == false)
			dfs1(i);
	}

	vector <int> graph2[n + 1];

	for(int i = 1; i <= n; ++i)
	{
		for(auto child : graph[i])
		{
			graph2[child].push_back(i);
		}
	}

	vis = vector <bool> (n + 1, false);

	function <void(int)> dfs2;

	dfs2 = [&](int node)
	{
		vis[node] = true;

		for(auto child : graph2[node])
		{
			if(vis[child] == false)
				dfs2(child);
		}
	};

	int components = 0;

	while(st.size())
	{
		int node = st.top();
		st.pop();

		if(vis[node] == false)
		{
			dfs2(node);
			components++;
		}
	}

	cout << components << "\n";
}
