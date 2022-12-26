#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int n, k;
vector <vector <ll>> tree;

void update (int node, int s, int e, int id, vector <ll> &a) {

    if (s == e) {
        tree[node] = a;
    } else {
        int mid = (s + e) / 2;
        if (s <= id and id <= mid)
            update (2 * node, s, mid, id, a);
        else
            update (2 * node + 1, mid + 1, e, id, a);
        for (int i = 0; i <= k; ++i) {
            tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
        }
    }

}

vector <ll> query (int node, int s, int e, int l, int r) {

    if (e < l or r < s)
        return vector <ll> (k + 1, 0);

    if (s == e) {
        return tree[node];
    } else if (l <= s and e <= r) {
        return tree[node];
    } else {
        int mid = (s + e) / 2;
        vector <ll> left = query (2 * node, s, mid, l, r);
        vector <ll> right = query (2 * node + 1, mid + 1, e, l, r);
        vector <ll> result(k + 1, 0);
        for (int i = 1; i <= k; ++i) {
            result[i] = left[i] + right[i];
        }
        return result;
    }

}

void DestroyInSeconds () {
    
    cin >> n >> k;
    k = (k + 1) * 1;

    int a[n];
    for (auto &i : a) 
        cin >> i;

    tree.assign(4 * n, vector <ll> (k + 1, 0));

    for (int i = 0; i < n; ++i) {
        vector <ll> ans(k + 1, 0);
        ans = query(1, 1, n, 1, a[i] - 1);
        for (int j = k; j >= 2; j--) {
            ans[j] = ans[j - 1];
        }
        ans[1] = 1;
        update(1, 1, n, a[i], ans);
    }

    cout << tree[1][k] << "\n";

}    

int32_t main () {

    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 

    while (testcases-- > 0)
        DestroyInSeconds ();

}
