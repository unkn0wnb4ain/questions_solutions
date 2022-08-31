#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	int houses;
	cin >> houses;

	int red[houses];
	int blue[houses];
	int green[houses];

	for(int i = 0; i < houses; ++i)	
		cin >> red[i] >> blue[i] >> green[i];

	int painted_red[houses] = {0};
	int painted_blue[houses] = {0};
	int painted_green[houses] = {0};

	painted_red[0] = red[0];
	painted_blue[0] = blue[0];
	painted_green[0] = green[0];

	for(int i = 1; i < houses; ++i)
	{
		painted_red[i] = red[i] + min(painted_blue[i - 1], painted_green[i - 1]);
		painted_blue[i] = blue[i] + min(painted_red[i - 1], painted_green[i - 1]);
		painted_green[i] = green[i] + min(painted_red[i - 1], painted_blue[i - 1]);
	}

	cout << min({painted_red[houses - 1], painted_blue[houses - 1], painted_green[houses - 1]}) << "\n";
}
