#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class SegmentTree
{
private:
    long long n;
    long long k;
    vector <long long> v;
    vector <long long> tree;
    vector <long long> lazy;

    void Build (int node, int s, int e)
    {
        if (s == e)
            tree[node] = v[s];
        else
        {
            int mid = (s + e) / 2;
            Build (2 * node, s, mid);
            Build (2 * node + 1, mid + 1, e);

            tree[node] = (tree[2 * node] + tree[2 * node + 1]);
        }
    }

    long long Point_query (int node, int s, int e, int l, int r)
    {
        if (s > r or e < l)
            return 0;

        if (l <= s and e <= r)
            return tree[node];

        int mid = (s + e) / 2;
        long long left = Point_query(2 * node, s, mid, l, r);
        long long right = Point_query(2 * node + 1, mid + 1, e, l, r);

        return (left + right);
    }

    void Point_update(int node, int s, int e, int pos, long long val)
    {
        if (s == e)
        {
            v[s] = val;
            tree[node] = val;
        }
        else
        {
            ll mid = (s + e) / 2;
            if (s <= pos and pos <= mid)
                Point_update(2 * node, s, mid, pos, val);
            else
                Point_update(2 * node + 1, mid + 1, e, pos, val);

            tree[node] = (tree[2 * node] + tree[2 * node + 1]);
        }
    }

    void Build2 (int node, int s, int e)
    {
        if (s == e)
            lazy[node] = v[s];
        else
        {
            int mid = (s + e) >> 1;
            Build2 (2 * node, s, mid);
            Build2 (2 * node + 1, mid + 1, e);
        }
    }

    void Range_update (int node, int s, int e, int l, int r, long long val)
    {
        if (s > r or e < l)
            return;

        if (s == e)
            lazy[node] += val;
        else if (l <= s and e <= r)
            lazy[node] += val;
        else
        {
            int mid = (s + e) >> 1;
            Range_update (2 * node, s, mid, l, r, val);
            Range_update (2 * node + 1, mid + 1, e, l, r, val);
        }
    }

    void propagate (int node)
    {
        int l = 2 * node;
        int r = 2 * node + 1;
        lazy[l] += lazy[node];
        lazy[r] += lazy[node];
        lazy[node] = 0;
    }

    long long lazy_query (int node, int s, int e, int id)
    {
        if (s == e)
            return lazy[node];

        propagate(node);

        int mid = (s + e) >> 1;
        if (s <= id and id <= mid)
            return lazy_query (2 * node, s, mid, id);
        else
            return lazy_query (2 * node + 1, mid + 1, e, id);
    }

public:
    SegmentTree (long long n, vector <long long> v)
    {
        this -> n = n;
        this -> v = v;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        Build(1, 0, n - 1);
        Build2(1, 0, n - 1);
    }

    void Point_update (int pos, long long val)
    {
        Point_update(1, 0, n - 1, pos, val);
    }

    void Range_update (int l, int r, long long val)
    {
        Range_update (1, 0, n - 1, l, r, val);
    }

    long long query (int id)
    {
        long long res = lazy_query(1, 0, n - 1, id);
        return res;
    }
};

void DestroyInSeconds()
{
    ll n;
    cin >> n;

    vector <ll> a(n);
    for (auto &i : a) 
        cin >> i;

    SegmentTree sg(n, a);

    int q;
    cin >> q;

    while (q-- > 0)
    {
        ll t;
        cin >> t;

        if (t == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            sg.Range_update(l, r, val);
        }

        else
        {
            ll id;
            cin >> id;
            cout << sg.query(id) << "\n";
        }
    }
}    

int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 

    while (testcases-- > 0)
        DestroyInSeconds();
}
        
