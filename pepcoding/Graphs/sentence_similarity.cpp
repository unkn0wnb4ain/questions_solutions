#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Dsu
{

private:
	int n;

public:
	map <string, int> size;
	map <string, string> parr;

	void Make(string s)
	{
		parr[s] = s;
		size[s] = 1;
	}

	string Find(string a)
	{
		if(parr[a] == a)
			return a;

		parr[a] = Find(parr[a]);
		return parr[a];
	}

	void Union(string a, string b)
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

};

int32_t main()
{
	int n;
	cin >> n;

	vector <string> sentence1(n);
	vector <string> sentence2(n);

	Dsu d;

	for(auto &i : sentence1) 
		cin >> i,
		d.Make(i);

	for(auto &i : sentence2) 
		cin >> i,
		d.Make(i);	

	int m;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		string a, b;
		cin >> a >> b;

		d.Union(a, b);
	}

	for(int i = 0; i < n; ++i)
	{
		string a = sentence1[i];
		string b = sentence2[i];

		if(d.Find(a) != d.Find(b))
		{
			cout << "false\n";
			goto done;
		}
	}

	cout << "true\n";

	done:;
}
