#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Lca
{
private:
    int n, L;
    vector <int> level;
    vector <vector <int>> ancestor;

    void dfs (int node, int par, vector <vector <int>> &graph)
    {
        level[node] = (node ? level[par] + 1 : 0);
        ancestor[node][0] = par;
        for (auto child : graph[node])
            dfs(child, node, graph);
    }

    int Binary_lifting(int node, int k)
    {
        for (int i = 0; i < L; ++i) 
            if ((k >> i) & 1) 
                node = ancestor[node][i];

        return node;
    }

public:
    Lca (int n, int L, vector <vector <int>> &graph)
    {
        this -> n = n;
        this -> L = L;
        level.assign(n, 0);
        ancestor.assign(n, vector <int> (L, 0));

        dfs(0, 0, graph);

        for (int i = 1; i <= L; ++i)
            for (int j = 1; j < n; ++j)
                ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
    }

    int Get(int u, int v)
    {
        if (level[u] > level[v])
            swap(u, v);
        int k = level[v] - level[u];
        v = Binary_lifting(v, k);
        if (u == v)
            return v;
        for (int i = L - 1; i >= 0; i--)
        {
            if (ancestor[u][i] != ancestor[v][i])
            {
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }
        return Binary_lifting(u, 1);
    }

    int Dist(int u, int v)
    {
        int d1 = level[u];
        int d2 = level[v];
        int d3 = 2 * level[Get(u, v)];
        return d1 + d2 - d3;
    }
};

int t = 1;
void print ()
{
    cout << "Case ";
    cout << t++ << ":\n";
}

void DestroyInSeconds()
{
    int n;
    cin >> n;

    print();

    vector <vector <int>> graph(n);

    for (int i = 0; i < n; ++i)
    {
        int c;
        cin >> c;

        for (int j = 0, x; j < c; ++j)
        {
            cin >> x;
            graph[i].push_back(x - 1);
        }
    }

    Lca l(n, 15, graph);

    int q;
    cin >> q;

    while (q-- > 0)
    {
        int a, b;
        cin >> a >> b;

        cout << l.Get(a - 1, b - 1) + 1 << "\n";
    }
}    

int32_t main()
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);

    ll testcases = 1; 
    cin >> testcases; 

    while (testcases-- > 0)
        DestroyInSeconds();
}
