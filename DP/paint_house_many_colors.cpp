#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int houses, colors;
	cin >> houses >> colors;

	vector <vector <int>> paints(houses, vector <int> (colors, 0));

	for(int i = 0; i < houses; ++i) 
		for(int j = 0; j < colors; ++j) 
			cin >> paints[i][j];

	vector <vector <int>> cost(houses, vector <int> (colors, 0));

	for(int i = 0; i < houses; ++i)
		cost[0][i] = paints[0][i];

	for(int i = 1; i < houses; ++i)
	{
		for(int j = 0; j < colors; ++j)
		{
			int mn = INT_MAX;
			for(int k = 0; k < colors; ++k)
			{
				if(k == j)
					continue;

				mn = min(mn, cost[i - 1][k]);
			}
			cost[i][j] = paints[i][j] + mn;
		}
	}

	int min_cost = INT_MAX;

	for(int i = 0; i < colors; ++i)
		min_cost = min(min_cost, cost[houses - 1][i]);

	cout << min_cost << "\n";
}
