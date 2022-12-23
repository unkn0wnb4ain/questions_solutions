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

    void propagate (int node, int s, int e)
    {
        if (s == e) 
        {
            tree[node] += lazy[node];
            lazy[node] = 0;
        } 
        else 
        {
            tree[node] += (e - s + 1) * lazy[node];
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void Range_update (int node, int s, int e, int l, int r, long long val)
    {
        propagate (node, s, e);
        if (e < l or r < s)
            return;

        if (s == e)
            tree[node] += val;
        else if (l <= s and e <= r) 
        {
            lazy[node] += val;
            propagate (node, s, e);
        } 
        else 
        {
            int mid = (s + e) / 2;
            Range_update(node * 2, s, mid, l, r, val);
            Range_update(node * 2 + 1, mid + 1, e, l, r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    long long Range_query (int node, int s, int e, int l, int r)
    {
        if (e < l or r < s)
            return 0;
        propagate (node, s, e);
        if (s == e) 
            return tree[node];
        else if (l <= s and e <= r) 
            return tree[node];   
        else 
        {
            int mid = (s + e) / 2;
            int left = Range_query(node * 2, s, mid, l, r);
            int right = Range_query(node * 2 + 1, mid + 1, e, l, r);
            return left + right;
        }
    }

public:
    SegmentTree (long long n, vector <long long> v)
    {
        this -> n = n;
        this -> v = v;
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
        Build(1, 0, n - 1);
    }

    void Range_update (int l, int r, long long val)
    {
        Range_update (1, 0, n - 1, l, r, val);
    }

    long long Query (int l, int r)
    {
        long long res = Range_query (1, 0, n - 1, l, r);
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
            sg.Range_update (l, r, val);
        }

        else
        {
            ll l, r;
            cin >> l >> r;
            cout << sg.Query(l, r) << "\n";
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
        
