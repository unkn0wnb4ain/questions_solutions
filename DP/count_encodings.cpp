#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;

	int n = s.size();
	int dp[n] = {0};

	dp[0] = 1;
	//dp[i] --> no. of encodings for string upto ith index

	for(int i = 1; i < n; ++i)	
	{
		if(s[i - 1] == '0')
		{
			if(s[i] != '0')
				dp[i] = dp[i - 1];
		}
		else
		{
			if(s[i] != '0')
				dp[i] = dp[i - 1];

			if(stoi(s.substr(i - 1, 2)) <= 26)
				dp[i] += (i == 1 ? 1 : dp[i - 2]);
		}
	}

	cout <<	dp[n - 1] << "\n";
}
