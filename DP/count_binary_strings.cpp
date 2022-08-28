#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int n;
	cin >> n;

	int zero_ct = 1; //value of zero_ct after ith iteration denotes number of appropriate strings of length i ending with 0
	int one_ct = 1; //same for one_ct

	for(int i = 2; i <= n; ++i)
	{
		int ztemp = one_ct;
		int otemp = one_ct + zero_ct;

		zero_ct = ztemp;
		one_ct = otemp;
	}

	cout << zero_ct + one_ct << "\n";
}
