#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct vertex {
    long long sum = 0;
    long long max = 0;
};

class SegmentTree {
private:
    long long n;
    vector <vertex> tree;
    vector <long long> a;

    void Build (int node, int s, int e) {
        if (s == e)
            tree[node] = {a[s], a[s]};
        else {
            int mid = (s + e) / 2;
            Build (2 * node, s, mid);
            Build (2 * node + 1, mid + 1, e);
            tree[node] = {max({tree[2 * node].sum,  tree[2 * node + 1].sum, tree[2 * node].max + tree[2 * node + 1].max}),
            max({tree[2 * node].max,  tree[2 * node + 1].max})};
        }
    }

    void Update (int node, int s, int e, int id, long long val) {
        if (s == e) {
            a[s] = val;
            tree[node] = {val, val};
        }
        else {
            int mid = (s + e) / 2;
            if (s <= id and id <= mid)
                Update (2 * node, s, mid, id, val);
            else
                Update (2 * node + 1, mid + 1, e, id, val);
            tree[node] = {max({tree[2 * node].sum,  tree[2 * node + 1].sum, tree[2 * node].max + tree[2 * node + 1].max}),
            max({tree[2 * node].max,  tree[2 * node + 1].max})};
        }
    }

    vertex Query (int node, int s, int e, int l, int r) {
        if (r < s or e < l)
            return {0ll, 0ll};
        if (s == e) {
            return tree[node];
        }
        if (l <= s and e <= r) {
            return tree[node];
        }
        int mid = (s + e) / 2;
        vertex left = Query (2 * node, s, mid, l, r);
        vertex right = Query (2 * node + 1, mid + 1, e, l, r);
        vertex res = {max({left.sum, right.sum, left.max + right.max}), max(left.max, right.max)};
        return res;
    }

public:
    SegmentTree (long long n, vector <long long> a) {
        this -> n = n;
        this -> a = a;
        tree.assign(4 * n, {0, 0});
        Build (1, 0, n - 1);
    }

    void Update (int id, long long val) {
        Update (1, 0, n - 1, id, val);
    }

    vertex Query (int l, int r) {
        // for (auto [x, y] : tree)
        //     cout << x << " " << y << "\n";
        return Query (1, 0, n - 1, l, r);
    }
};

void DestroyInSeconds () {
    int n;
    cin >> n;

    vector <ll> a(n);
    for (auto &i : a) { 
        cin >> i;
    }

    SegmentTree sg (n, a);

    int q;
    cin >> q;
    while (q-- > 0) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l, r;
            cin >> l >> r;
            cout << sg.Query (l, r).sum << "\n";
        }
        else {
            ll id, val;
            cin >> id >> val;
            sg.Update (id, val);
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
