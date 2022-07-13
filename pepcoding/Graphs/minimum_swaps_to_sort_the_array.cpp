#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n;
    cin >> n;

    vector <int> a(n);
    vector <pair <int, int>> v(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        v[i].first = a[i];
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector <bool> vis(n, false);

    int ans = 0;

    for(int i = 0; i < n; ++i)
    {
        if(vis[i] || v[i].second == i)
            continue;

        int j = i, cycle_len = 0;
        while(!vis[j])
        {
            vis[j] = true;
            j = v[j].second;
            cycle_len++;
        }

        ans += (cycle_len - 1);
    }

    cout << ans << endl;

}

