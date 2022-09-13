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

	vector <int> dp(n, 1);

	int lis = 1;

	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < i; ++j)
			if(a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
			
		lis = max(lis, dp[i]);
	}

	cout << lis << "\n";
}
