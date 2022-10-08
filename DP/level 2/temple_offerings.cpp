#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int a[n];
	for (auto &i : a) 
		cin >> i;	

	int left[n]; left[0] = 1;
	int right[n]; right[n - 1] = 1;

	for (int i = 1; i < n; ++i)
	{
		if (a[i] > a[i - 1])
			left[i] = left[i - 1] + 1;

		else
			left[i] = 1;
	}

	for (int i = n - 2; i >= 0; --i)
	{
		if (a[i] > a[i + 1])
			right[i] = right[i + 1] + 1;

		else
			right[i] = 1;
	}

	long long ans = 0;

	for (int i = 0; i < n; ++i)
		ans += max(left[i], right[i]);

	cout << ans << "\n";
}
