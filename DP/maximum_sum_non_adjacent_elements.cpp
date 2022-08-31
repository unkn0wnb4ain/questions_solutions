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

	int include = a[0];
	int exclude = 0;

	for(int i = 1; i < n; ++i)
	{
		int new_in = a[i] + exclude;
		int new_ex = max(include, exclude);

		include = new_in;
		exclude = new_ex;
	}

	cout << max(include, exclude) << "\n";
}
