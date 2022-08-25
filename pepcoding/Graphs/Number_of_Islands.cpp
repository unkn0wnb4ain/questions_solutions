#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Dsu
{

private:
	int n;
	vector <int> size;

public:
	vector <int> parr;

	Dsu(int n)
	{
		this -> n = n;
		parr.assign(n + 1, -1);
		size.assign(n + 1, -1);
	}

	void Build(int a)
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
	int n, m, k;
	cin >> n >> m >> k;

	Dsu Islands(n * m);

	int count = 0;
	vector <int> ans;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	for(int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;

		int cell_no = x * m + y;

		if(Islands.parr[cell_no] != -1)
			ans.push_back(count);

		else
		{
			Islands.Build(cell_no);

			count++;

			for(int j = 0; j < 4; ++j)
			{
				int row = x + dx[j];
				int col = y + dy[j];
				int new_cell_no = row * m + col;

				if(row < 0 || col < 0 || row >= n || col >= m || Islands.parr[new_cell_no] == -1)
					continue;

				if(Islands.Find(cell_no) != Islands.Find(new_cell_no))
				Islands.Union(cell_no, new_cell_no),
				count--;
			}

			ans.push_back(count);
		}
	}

	int ct = 0;
	cout << "[";
	for(auto i : ans)
	{
		if(ct)
			cout << ", ";
		cout << i, ct++;
	}
	cout << "]";

}
