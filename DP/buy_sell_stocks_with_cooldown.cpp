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

	int bp = -a[0];
	int sp = 0;
	int cp = 0;

	for(int i = 1; i < n; ++i)
	{
		int new_bp = cp - a[i];
		int new_sp = bp + a[i];
		int new_cp = sp;

		bp = max(bp, new_bp);
		sp = max(sp, new_sp);
		cp = max(cp, new_cp);
	}

	cout << sp << "\n";
}
