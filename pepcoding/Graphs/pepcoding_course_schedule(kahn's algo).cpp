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
		int x, y;
		cin >> y >> x;

		graph[x].push_back(y);
	}

	vector <int> ordering;
	vector <int> indegree(n + 1, 0);

	for(int i = 0; i < n; ++i)
	{
		for(auto child : graph[i])
			indegree[child]++;
	}

	queue <int> q;

	for(int i = 0; i < n; ++i)
	{
		if(indegree[i] == 0)
			q.push(i);
	}

	int count = 0;

	while(q.size())
	{
		int node = q.front();
		q.pop();

		ordering.push_back(node);
		count++;

		for(auto child : graph[node])
		{
			indegree[child]--;

			if(indegree[child] == 0)
				q.push(child);
		}
	}

	if(count == n)
	{
		for(auto &i : ordering) 
			cout << i << " ";
		cout << '\n';	
	}

	else
		cout << -1 << '\n';
}
