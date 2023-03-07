#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int timer = 1;
vector <int> lt;
vector <int> val;
vector <int> endd;
vector <int> start;
 
class SegmentTree
{
private:
    long long n;
    long long k;
    vector <int> v;
    vector <long long> tree;
 
public:
    SegmentTree (long long n, vector <int> v)
    {
        this -> n = n;
        this -> v = v;
        tree.assign(4 * n + 1, 0);
        Build(1, 1, n);
    }
 
    void Build (int node, int s, int e)
    {
        if (s == e)
            tree[node] = v[s];
        else
        {
            int mid = (s + e) / 2;
            Build ((node << 1), s, mid);
            Build ((node << 1) | 1, mid + 1, e);
            tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
        }
    }
 
    long long Get_query (int node, int s, int e, int l, int r)
    {
        if (s > r or e < l)
            return 0;
 
        if (l <= s and e <= r)
            return tree[node];
 
        int mid = (s + e) / 2;
        long long left = Get_query(node << 1, s, mid, l, r);
        long long right = Get_query(node << 1 | 1, mid + 1, e, l, r);
 
        return (left + right);
    }
 
    long long Query (int l, int r)
    {
        long long res = Get_query(1, 1, n, l, r);
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
                Do_update(node << 1, s, mid, pos, val);
            else
                Do_update(node << 1 | 1, mid + 1, e, pos, val);
 
            tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
        }
    }
 
    void Update (int pos, long long val)
    {
        Do_update(1, 1, n, pos, val);
    }
};
 
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
 
    int n, q;
    cin >> n;
 
    val.resize(n + 1);
    for (int i = 1; i <= n; ++i)     
    {
        cin >> val[i];
    }
 
    vector <int> tree[n + 1];
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
 
    endd.resize(n + 1);
    start.resize(n + 1);
    lt.resize(2 * n + 2);
 
    function <void(int, int)> dfs = [&](int node, int p)
    {
        start[node] = timer;
        lt[timer++] = val[node];
        for (auto child : tree[node])
        {
            if (child != p)
            {
                dfs(child, node);
            }
        }
        endd[node] = timer;
        lt[timer++] = -val[node];
    };
 
    dfs(1, -1);
    SegmentTree sg(2 * n + 2, lt);
    
    cin >> q;
    while (q-- > 0) 
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int s, x;
            cin >> s >> x;
            sg.Update(start[s], x);
            sg.Update(endd[s], -x);
        }
        else
        {
            int v;
            cin >> v;
            cout << sg.Query(0, start[v]) << "\n";
        }
    }
}
