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

	int k;
	cin >> k;

	int maxSum[n];

	int curr = maxSum[0] = a[0];

	for(int i = 1; i < n; ++i)
	{
		if(curr < 0)
			curr = a[i];

		else
			curr += a[i];

		maxSum[i] = curr;
	}

	int ksum = 0;
	for(int i = 0; i < k; ++i)
		ksum += a[i];

	int ans = ksum;

	for(int i = k; i < n; ++i)
	{
		ksum = ksum - a[i - k] + a[i];

		ans = max(ans, ksum);

		ans = max(ans, ksum + maxSum[i - k]);
	}

	cout << ans << "\n";
}
