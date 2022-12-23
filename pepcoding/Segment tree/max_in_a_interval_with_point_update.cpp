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

public:
    SegmentTree (long long n, vector <long long> v)
    {
        this -> n = n;
        this -> v = v;
        tree.assign(4 * n, 0);
        Build(1, 0, n - 1);
    }

    void Build (int node, int s, int e)
    {
        if (s == e)
            tree[node] = v[s];
        else
        {
            int mid = (s + e) / 2;
            Build (2 * node, s, mid);
            Build (2 * node + 1, mid + 1, e);

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    long long Get_query (int node, int s, int e, int l, int r)
    {
        if (s > r or e < l)
            return INT_MIN;

        if (l <= s and e <= r)
            return tree[node];

        int mid = (s + e) / 2;
        long long left = Get_query(2 * node, s, mid, l, r);
        long long right = Get_query(2 * node + 1, mid + 1, e, l, r);

        return max(left, right);
    }

    long long Query (int l, int r)
    {
        long long res = Get_query(1, 0, n - 1, l, r);
        return res;
    }

    void Do_update(int node, int s, int e, int pos, long long val)
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
                Do_update(2 * node, s, mid, pos, val);
            else
                Do_update(2 * node + 1, mid + 1, e, pos, val);

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void Update (int pos, long long val)
    {
        Do_update(1, 0, n - 1, pos, val);
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
            ll l, r;
            cin >> l >> r;
            cout << sg.Query(l, r) << "\n";
        }

        else
        {
            ll pos, val;
            cin >> pos >> val;
            sg.Update(pos, val);
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
        
