#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class SegmentTree {
private:
    struct vertex {
        ll sum = 0;
        ll sqs = 0;
    };

    ll n;
    vector <ll> a; 
    vector <ll> lazy;
    vector <vertex> tree;

    void Build (int node, int s, int e) {
        if (s == e) {
            tree[node] = {a[s], a[s] * a[s]};
        } else {
            int mid = (s + e) / 2;
            Build (2 * node, s, mid);
            Build (2 * node + 1, mid + 1, e);
            tree[node] = {(tree[2 * node].sum + tree[2 * node + 1].sum), (tree[2 * node].sqs + tree[2 * node + 1].sqs)};
        }
    }

    void Propagate (int node, int s, int e) {
        if (lazy[node] == 0) {
            return;
        }
        if (s == e) {
            tree[node].sum += lazy[node];
            tree[node].sqs = (tree[node].sum * tree[node].sum);
            lazy[node] = 0;
        } else {
            int count = (e - s + 1);
            tree[node].sqs += (count * lazy[node] * lazy[node] + 2 * lazy[node] * tree[node].sum);
            tree[node].sum += (count * lazy[node]);
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }
    
    void Update (int node, int s, int e, int l, int r, int val) {
        Propagate (node, s, e);
        if (e < l or r < s) {
            return;
        }
        if (s == e) {
            lazy[node] += val;
            Propagate (node, s, e);
        } else if (l <= s and e <= r) {
            lazy[node] += val;
            Propagate (node, s, e);
        } else {
            int mid = (s + e) / 2;
            Update (2 * node, s, mid, l, r, val);
            Update (2 * node + 1, mid + 1, e, l, r, val);
            tree[node] = {(tree[2 * node].sum + tree[2 * node + 1].sum), tree[2 * node].sqs + tree[2 * node + 1].sqs};
        }
    }
    
    vertex Query (int node, int s, int e, int l, int r) {
        Propagate (node, s, e);
        if (e < l or r < s) {
            return {0, 0};
        } else if (s == e) {
            return tree[node];
        } else if (l <= s and e <= r) {
            return tree[node];
        } else {
            int mid = (s + e) / 2;
            vertex left = Query (2 * node, s, mid, l, r);
            vertex right = Query (2 * node + 1, mid + 1, e, l, r);
            vertex res = {left.sum + right.sum, left.sqs + right.sqs};
            return res;
        }
    }

public:
    SegmentTree (ll n, vector <ll> a) {
        this -> n = n;
        this -> a = a;
        tree.assign(4 * n, {0, 0});
        lazy.assign(4 * n, 0);
        Build (1, 0, n - 1);
    }

    void Update (int l, int r, int val) {
        Update (1, 0, n - 1, l, r, val);
    }

    long long Query (int l, int r) {
        vertex res = Query (1, 0, n - 1, l, r);
        return res.sqs;
    }
};

void DestroyInSeconds () {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    SegmentTree sg(n, a);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            sg.Update(l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
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
