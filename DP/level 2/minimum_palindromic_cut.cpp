#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int32_t main()
{
	string s;
	cin >> s;
	int n = s.size();
    
    vector <vector <bool>> dp1(n, vector <bool> (n, 0));
    
    for(int gap = 0; gap < n; ++gap)
    {
        for(int i = 0, j = gap; j < n; ++i, ++j)
        {
            if(gap == 0)
                dp1[i][j] = 1;
            
            else if(gap == 1)
                dp1[i][j] = (s[i] == s[j]);
            
            else
            {
                dp1[i][j] = (s[i] == s[j] && dp1[i + 1][j - 1]);
            }
        }
    }
    
    vector <int> dp2(n, 0);
    dp2[0] = 0;
    
    for(int j = 1; j < n; ++j)
    {
        if(dp1[0][j])
            dp2[j] = 0;
        
        else
        {
            int mn = INT_MAX;
            for(int i = j; i >= 1; i--)
            {
                if(dp1[i][j])
                    mn = min(mn, dp2[i - 1]);
            }
            dp2[j] = mn + 1;
        }
    }	

    cout << dp2[n - 1] << "\n";
}		
