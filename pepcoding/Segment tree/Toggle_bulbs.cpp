#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class SegmentTree {
    ll n;
    vector <ll> tree;
    vector <ll> lazy;
    
    void Propagate (int node, int s, int e) {
        if (lazy[node] == 0)
            return;
        if (s == e) {
            tree[node] ^= 1;
            lazy[node] = 0;
        } else {
            tree[node] = (e - s + 1) - tree[node];
            lazy[2 * node] ^= 1;
            lazy[2 * node + 1] ^= 1;
            lazy[node] = 0;
        }
    }

    void Update (int node, int s, int e, int l, int r) {
        Propagate (node, s, e);
        if (e < l or s > r) {
            return;
        }
        if (s == e) {
            tree[node] ^= 1;
        } else if (l <= s and e <= r) {
            lazy[node] ^= 1;
            Propagate (node, s, e);
        } else {
            int mid = (s + e) / 2;
            Update(2 * node, s, mid, l, r);
            Update(2 * node + 1, mid + 1, e, l, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    ll Query (int node, int s, int e, int l, int r) {
        if (e < l or r < s)
            return 0ll;
        Propagate(node, s, e);
        if (s == e) {
            return tree[node];
        } else if (l <= s and e <= r) {
            return tree[node];
        } else {
            int mid = (s + e) / 2;
            ll left = Query(2 * node, s, mid, l, r);
            ll right = Query(2 * node + 1, mid + 1, e, l, r);
            return (left + right);
        }
    }

public:
    SegmentTree (ll n) {
        this -> n = n;
        tree.assign(4 * n + 2, 0);
        lazy.assign(4 * n + 2, 0);
    }

    void Update (int l, int r) {
        Update (1, 1, n, l, r);
    }

    ll Query (int l, int r) {
        return Query (1, 1, n, l, r);
    }
};

void DestroyInSeconds () {
    int n, q;
    cin >> n >> q;
    SegmentTree sg(n);
    while (q-- > 0) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            sg.Update(l, r);
        } else {
            cout << sg.Query(l, r) << "\n";
        }
    }
}    

int32_t main () {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 

    while (testcases-- > 0)
        DestroyInSeconds ();
}       
