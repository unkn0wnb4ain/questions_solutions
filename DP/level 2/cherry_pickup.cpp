#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int dp[52][52][52];

int cherry_pick(int r1, int c1, int r2, vector <vector <int>> &a)
{
	int c2 = r1 + c1 - r2;
	int cherries = 0;
	int n = a.size();
	int m = a[0].size();

	if(r1 >= n || c1 >= m || r2 >= n || c2 >= m)
		return 0;

	if(dp[r1][c1][r2] != -1)
		return dp[r1][c1][r2];

	if(a[r1][c1] == -1 || a[r2][c2] == -1)
		return INT_MIN;

	if(r1 == n - 1 && c1 == m - 1)
		return a[r1][c1];

	if(r2 == n - 1 && c2 == m - 1)
		return a[r2][c2];

	if(r1 == r2 && c1 == c2)
		cherries = a[r1][c1];

	else
		cherries = a[r1][c1] + a[r2][c2];

	int f1 = cherry_pick(r1, c1 + 1, r2 + 1, a);
	int f2 = cherry_pick(r1 + 1, c1, r2, a);
	int f3 = cherry_pick(r1 + 1, c1, r2 + 1, a);
	int f4 = cherry_pick(r1, c1 + 1, r2, a);

	cherries += max({f1, f2, f3, f4});

	return dp[r1][c1][r2] = cherries;
}

int32_t main()
{
	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	vector <vector <int>> a(n, vector <int> (n, 0));
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j) 
			cin >> a[i][j];

	cout << cherry_pick(0, 0, 0, a);
}		
