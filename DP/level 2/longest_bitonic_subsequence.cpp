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

	vector <int> inc(n, 1);
	vector <int> dec(n, 1);

	for(int i = 1; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if(a[j] <= a[i])
				inc[i] = max(inc[i], inc[j] + 1);

	for(int i = n - 2; i >= 0; --i)
		for(int j = n - 1; j > i; --j)
			if(a[j] <= a[i])
				dec[i] = max(dec[i], dec[j] + 1);

	int ans = 0;

	for(int i = 0; i < n; ++i)
		ans = max(ans, inc[i] + dec[i] - 1);

	cout << ans << "\n";
}
