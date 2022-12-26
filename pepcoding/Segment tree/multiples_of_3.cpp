#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <int> lazy;
vector <vector <int>> tree;

void cal (vector <int> &a, vector <int> &b, vector <int> &c) {
    
    a[0] = b[0] + c[0];
    a[1] = b[1] + c[1];
    a[2] = b[2] + c[2];
}

void Build (int node, int s, int e) {

    if (s == e) {
        tree[node][0] = 1;
    } else {
        int mid = (s + e) / 2;
        Build (2 * node, s, mid);
        Build (2 * node + 1, mid + 1, e);
        cal(tree[node], tree[node * 2], tree[node * 2 + 1]);
    }

}

void shift (vector <int> &a) {

    int temp = a[0];
    a[0] = a[2];
    a[2] = a[1];
    a[1] = temp;

}

void propagate (int node, int s, int e) {

    lazy[node] = lazy[node] % 3;

    int temp = lazy[node];
    while (lazy[node] > 0) {
        shift (tree[node]);
        lazy[node]--;
    }

    if (s != e) {
        lazy[2 * node] += temp;
        lazy[2 * node + 1] += temp;
    }

}

void update (int node, int s, int e, int l, int r) {

    propagate(node, s, e);

    if (e < l or s > r) {
        return;
    }

    if (s == e) {
        shift(tree[node]);
    } else if (l <= s and e <= r) {
        lazy[node]++;
        propagate(node, s, e);
    } else {
        int mid = (s + e) / 2;
        update (2 * node, s, mid, l, r);
        update (2 * node + 1, mid + 1, e, l, r);
        cal(tree[node], tree[node * 2], tree[node * 2 + 1]);
    }

}

int query (int node, int s, int e, int l, int r) {

    if (s > r or e < l) {
        return 0;
    }

    propagate(node, s, e);

    if (s == e) {
        return tree[node][0];
    } else if (l <= s and e <= r) {
        return tree[node][0];
    } else {
        int mid = (s + e) / 2;
        return query(2 * node, s, mid, l, r) + query(2 * node + 1, mid + 1, e, l, r);
    }

}

void DestroyInSeconds () {

    int n;
    cin >> n;

    lazy.assign(4 * n + 2, 0);
    tree = vector <vector <int>> (4 * n + 2, vector <int> (3, 0));

    Build(1, 1, n);

    int q;
    cin >> q;

    while (q-- > 0) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1) {
            update(1, 1, n, l, r);
        } else {
            cout << query(1, 1, n, l, r) << "\n";
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
