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

	int fee;
	cin >> fee;

	int bp = -a[0];
	int sp = 0;

	for(int i = 1; i < n; ++i)
	{
		int new_bp = sp - a[i];
		int new_sp = bp + a[i] - fee;

		bp = max(bp, new_bp);
		sp = max(sp, new_sp);
	}

	cout << sp << "\n";
}
