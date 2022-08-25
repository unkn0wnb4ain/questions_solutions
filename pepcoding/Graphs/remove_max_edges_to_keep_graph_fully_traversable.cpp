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

	void Make()
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

	int components()
	{
		int comps = 0;
		for(int i = 1; i <= n; ++i)
		{
			comps += parr[i] == i;
		}

		return comps;
	}
};

int32_t main()
{
	int n, m;
	cin >> n >> m;

	vector <pair <int, pair <int, int>>> edges(m);

	for(int i = 0; i < m; ++i)	
	{
		int t, a, b;
		cin >> t >> a >> b;

		edges[i] = {t, {a, b}};
	}

	sort(edges.begin(), edges.end(), [&](pair <int, pair <int, int>> &x, pair <int, pair<int, int>> &y)
	{
		return x.first > y.first;
	});

	Dsu Alice(n), Bob(n);

	Alice.Make();
	Bob.Make();

	int extra = 0;

	for(auto edge : edges)
	{
		int t = edge.first;
		int a = edge.second.first;
		int b = edge.second.second;

		if(t == 3)
		{
			if(Alice.Find(a) == Alice.Find(b) && Bob.Find(a) == Bob.Find(b))
				extra++;

			else
			{
				Alice.Union(a, b);
				Bob.Union(a, b);
			}
		}

		else if(t == 1)
		{
			if(Alice.Find(a) == Alice.Find(b))
				extra++;

			else
				Alice.Union(a, b);
		}

		else
		{
			if(Bob.Find(a) == Bob.Find(b))
				extra++;

			else
				Bob.Union(a, b);
		}
	}

	if(Alice.components() > 1 || Bob.components() > 1)
		cout << -1 << "\n";

	else
		cout << extra << "\n";
}
