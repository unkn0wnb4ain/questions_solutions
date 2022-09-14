#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for(auto &i : a) 
		cin >> i;	

	vector <vector <int>> dp(n - 1, vector <int> (n - 1, INT_MAX));

	/*
	for n = 6, dp will be like ---
		a a a a a
		x a a a a
		x x a a a
		x x x a a
		x x x x x
	
	d[i][j] -> cost of multiplication of matrices i & j
	a -> some value
	x -> irrelevant cells
	*/

	for(int gap = 0; gap < n - 1; ++gap)
	{
		for(int i = 0, j = gap; j < n - 1; ++i, ++j)
		{
			if(gap == 0)
				dp[i][j] = 0;

			else if(gap == 1)
				dp[i][j] = a[i] * a[j] * a[j + 1];

			else
			{
				//using k for partitioning
				//k varies from i to j - 1
				for(int k = i; k < j; ++k)
				{
					//in dp, left half -> i to k & right half -> k + 1 to j
					//in a, left half -> i to k + 1 & right half -> k + 1 to j + 1
					int left = dp[i][k];
					int right = dp[k + 1][j];
					int multiply = a[i] * a[k + 1] * a[j + 1];
					int total_cost = left + right + multiply;

					dp[i][j] = min(dp[i][j], total_cost);
				}
			}
		}
	}

	cout << dp[0][n - 2] << "\n";
}
