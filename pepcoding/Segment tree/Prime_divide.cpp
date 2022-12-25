#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector <int> a;
vector <vector <int>> tree;

void Propagate(int node, int s, int e) {
    if (s != e) {
        for (int i = 0; i < 3; ++i) {
            tree[2 * node][i] += tree[node][i];
            tree[2 * node + 1][i] += tree[node][i];
        }
    } else {
        while (a[s] % 2 == 0 and tree[node][0] > 0) {
            a[s] /= 2;
            tree[node][0]--;
        }
        while (a[s] % 3 == 0 and tree[node][1] > 0) {
            a[s] /= 3;
            tree[node][1]--;
        }
        while (a[s] % 5 == 0 and tree[node][2] > 0) {
            a[s] /= 5;
            tree[node][2]--;
        }
    }
    tree[node][0] = tree[node][1] = tree[node][2] = 0;
}

void Range_update(int node, int s, int e, int l, int r, int p) {
    if (s > r or e < l)
        return;
    if (l <= s and e <= r) {
        tree[node][p]++;
    } else {
        int mid = (s + e) / 2;
        Range_update(2 * node, s, mid, l, r, p);
        Range_update(2 * node + 1, mid + 1, e, l, r, p);
    }
}

void Point_update(int node, int s, int e, int id, int val) {
    Propagate (node, s, e);
    if (s == e) {
        a[s] = val;
    } else {
        int mid = (s + e) / 2;
        if (s <= id and id <= mid)
            Point_update(2 * node, s, mid, id, val);
        else 
            Point_update(2 * node + 1, mid + 1, e, id, val);
    }
}

void Propagate_final (int node, int s, int e) {
    Propagate (node, s, e);
    if (s == e)
        return;
    int mid = (s + e) / 2;
    Propagate_final (2 * node, s, mid);
    Propagate_final (2 * node + 1, mid + 1, e);
}

void DestroyInSeconds () {
    ll n;
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    tree = vector <vector <int>> (4 * n, vector <int> (3, 0));
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, p;
            cin >> l >> r >> p;
            if (p == 2) {
                Range_update(1, 0, n - 1, l - 1, r - 1, 0);
            } else if (p == 3) {
                Range_update(1, 0, n - 1, l - 1, r - 1, 1);
            } else {
                Range_update(1, 0, n - 1, l - 1, r - 1, 2);
            }
        } else {
            int id, val;
            cin >> id >> val;
            Point_update(1, 0, n - 1, id - 1, val);
        }
    }
    Propagate_final(1, 0, n - 1);
    for (int i = 0 ; i < n; ++i) {
        cout << a[i] << "\n";
    }
}    

int32_t main () {
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 

    while (testcases-- > 0)
        DestroyInSeconds ();
}           
