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

	vector <string> equations(n);

	for(int i = 0; i < n; ++i)		
		cin >> equations[i];

	Dsu d(25);
	d.Build();

	for(auto equation : equations)
	{
		if(equation[1] == '=')
		{
			d.Union(equation[0] - 'a', equation[3] - 'a');
		}
	}

	for(auto equation : equations)
	{
		if(equation[1] == '!')
		{
			if(d.Find(equation[0] - 'a') == d.Find(equation[3] - 'a'))
			{
				cout << "false\n";
				goto done;
			}
		}
	}

	cout << "true\n";

	done:;

}
