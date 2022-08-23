#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T>
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

	void Make(int a)
	{
		parr[a] = a;
		size[a] = 1;
	}

	int Find(int a)
	{
		if(parr[a] == a)
			return a;

		parr[a] = Find(parr[a]);
		return parr[a];
	}

	bool Union(int a, int b)
	{
		a = Find(a);
    	b = Find(b);
    	
    	if (a != b) {
        	if (size[a] < size[b])
            	swap(a, b);

        	parr[b] = a;
        	size[a] += size[b];

        	return true;
    	}		

    	else
    	{
    		return false;
    	}
	}

};

int32_t main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	vector <array <int, 3>> graph(m);

	for(int i = 0; i < m; ++i)	
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[i] = {c, a, b};
	}

	sort(graph.begin(), graph.end());

	int mst = 0;

	Dsu <int> D(n);

	for(int i = 0; i < n; ++i)
		D.Make(i);

	for(int i = 0; i < n; ++i)
	{
		int a = graph[i][1];
		int b = graph[i][2];
		int c = graph[i][0];

		if(D.Union(a, b))
			mst += c;
	}

	cout << mst << "\n";
}
