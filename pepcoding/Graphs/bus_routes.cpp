#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int buses, stops;
    cin >> buses >> stops;

    vector <vector <int>> a(buses + 1, vector <int> (stops + 1, 0));

    for(int i = 1; i <= buses; ++i)
    {
        for(int j = 1; j <= stops; ++j)
            cin >> a[i][j];
    }

    int start, end;
    cin >> start >> end;

    map <int, vector <int>> m;

    for(auto i = 1; i <= buses; ++i)
    {
        for(int j = 1; j <= stops; ++j)
        {
            m[a[i][j]].push_back(i);
        }
    }

    set <int> bus_stops, buses_taken;

    queue <int> q;
    q.push(start);

    bus_stops.insert(start);

    int min_buses = 0;

    function <void()> bfs;

    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                int front = q.front();
                q.pop();

                if(front == end)
                {
                    bus_stops.insert(end);
                    return;
                }

                vector <int> busess = m[front];

                for(auto bus : busess)
                {
                    if(buses_taken.count(bus))
                        continue;

                    for(int i = 1; i <= stops; ++i)
                    {
                        if(bus_stops.count(a[bus][i]))
                            continue;

                        q.push(a[bus][i]);
                        bus_stops.insert(a[bus][i]);
                    }

                    buses_taken.insert(bus);
                }
            }
            
            min_buses++;
        }
    };

    bfs();

    if(bus_stops.count(end))
        cout << min_buses << endl;

    else
        cout << -1 << endl;

}

