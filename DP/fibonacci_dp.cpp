#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll fib[100002];

ll recursive_fib(ll n)
{
    if(n <= 1)
        return n;

    if(fib[n] != -1)
        return fib[n];

    ll res = recursive_fib(n - 1) + recursive_fib(n - 2);

    return fib[n] = res;
}

int main()
{

    memset(fib, -1, sizeof(fib));

    ll n;
    cin >> n;

    fib[0] = 0; fib[1] = 1;

    for(int i = 2; i < n + 1; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n] << endl;

}
