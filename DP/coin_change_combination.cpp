#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int coins[n];
	for(auto &i : coins) 
		cin >> i;	

	int target;
	cin >> target;

	vector <int> dp(target + 1, 0);

	dp[0] = 1;

	for(auto coin : coins)
		for(int i = 1; i <= target; ++i)
			dp[i] += (coin <= i ? dp[i - coin] : 0);

	cout << dp[target] << "\n";

}
