#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int fences, colors;
	cin >> fences >> colors;

	if(fences == 1)
	{
		cout << colors << "\n";
		return 0;
	}

	int same = colors;
	int diff = colors * (colors - 1);
	int total = same + diff;

	for(int i = 2; i < fences; ++i)	
	{
		same = diff;
		diff = total * (colors - 1);
		total = same + diff;
	}

	cout << total << "\n";
}
