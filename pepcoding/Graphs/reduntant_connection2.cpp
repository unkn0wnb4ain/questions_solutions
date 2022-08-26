#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Dsu
{

private:
	int n;
	vector <int> parr;
	vector <int> size;

public:
	Dsu(int n)
	{
		this -> n = n;
		parr.assign(n + 1, 0);
		size.assign(n + 1, 0);
	}

	void Build()
	{
		for(int i = 0; i <= n; ++i)
		{
			parr[i] = i;
			size[i] = 1;
		}
	}

	int Find(int a)
	{
		if(parr[a] == a)
			return a;

		parr[a] = Find(parr[a]);
		return parr[a];
	}

	void Union(int a, int b)
	{
		a = Find(a);
    	b = Find(b);
    	
    	if (a != b) 
    	{
        	if (size[a] < size[b])
            	swap(a, b);

        	parr[b] = a;
        	size[a] += size[b];
    	}		
	}

	int Components()
	{
		int comps = 0;

		for(int i = 1; i <= n; ++i)
			comps += parr[i] == i;

		return comps;
	}

};

int32_t main()
{
	int n;
	cin >> n;

	Dsu d(n);
	d.Build();

	vector <pair <int, int>> edges(n);
	
	for(int i = 0; i < n; ++i)		
		cin >> edges[i].first >> edges[i].second;

	int black_listed1 = -1, black_listed2 = -1;

	vector <int> indegree(n + 1, -1);

	for(int i = 0; i < n; ++i)
	{
		int a = edges[i].first;
		int b = edges[i].second;

		if(indegree[b] == -1)
			indegree[b] = i;

		else
		{
			black_listed1 = i;
			black_listed2 = indegree[b];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int a = edges[i].first;
		int b = edges[i].second;

		if(i == black_listed1)
			continue;

		if(d.Find(a) != d.Find(b))
			d.Union(a, b);

		else
		{
			if(black_listed1 == -1)
				cout << a << " " << b << "\n";

			else
			{
				cout << edges[black_listed2].first << " " << edges[black_listed2].second << "\n";
			}

			goto done;
		}
	}

	cout << edges[black_listed1].first << " " << edges[black_listed1].second << "\n";

	done:;
}
