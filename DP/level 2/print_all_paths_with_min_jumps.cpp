#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct jump
{
	int id;
	int sz;
	int jp;
	string path;

	jump(int id, int sz, int jp, string path)
	{
		this -> id = id;
		this -> sz = sz;
		this -> jp = jp;
		this -> path = path;
	}
};

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for(int &i : a)
		cin >> i;

	vector <int> dp(n, INT_MAX);

	dp[n - 1] = 0;

	for(int i = n - 2; i >= 0; i--)
	{
		int mn = INT_MAX;
		for(int j = 1; j <= a[i] && i + j < n; ++j)
			mn = min(mn, dp[i + j]);

		if(mn != INT_MAX)
			dp[i] = mn + 1;
	}

	cout << dp[0] << "\n";

	queue <jump> q;
	jump jmp(0, a[0], dp[0], "0"); 
	q.push(jmp);

	while(q.size())
	{
		jump cur = q.front();
		q.pop();

		if(cur.jp == 0)
			cout << cur.path << " .\n";

		for(int i = 1; i <= cur.sz && i + cur.id < n; ++i)
		{
			int id_ = i + cur.id;

			if(dp[id_] != INT_MAX && dp[id_] == cur.jp - 1)
				q.push(jump(id_, a[id_], dp[id_], cur.path + " -> " + to_string(id_)));
		}
	}
}
