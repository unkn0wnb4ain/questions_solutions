#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    vector <vector <int>> a(2, vector <int> (3, 0));

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 3; ++j)
            cin >> a[i][j];
    }

    vector <vector <int>> solved = {{1, 2, 3}, {4, 5, 0}};

    set <vector <vector <int>>> present;

    queue <vector <vector <int>>> q;

    q.push(a);
    present.insert(a);

    int moves = 0;

    function <void()> bfs;

    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                vector <vector <int>> front = q.front();
                q.pop();

                if(front == solved)
                {
                    present.insert(solved);
                    return;
                }          

                int zi, zj;

                for(int i = 0; i < 2; ++i)
                {
                    for(int j = 0; j < 3; ++j)
                    {
                        if(front[i][j] == 0)
                            zi = i, zj = j;
                    }
                }  

                if(zj != 2)
                {
                    vector <vector <int>> copy1 = front;
                    swap(copy1[zi][zj], copy1[zi][zj + 1]);

                    if(!present.count(copy1))
                    {
                        q.push(copy1);
                        present.insert(copy1);
                    }
                }

                if(zj != 0)
                {
                    vector <vector <int>> copy2 = front;
                    swap(copy2[zi][zj], copy2[zi][zj - 1]);

                    if(!present.count(copy2))
                    {
                        q.push(copy2);
                        present.insert(copy2);
                    }
                }

                vector <vector <int>> copy3 = front;
                swap(copy3[zi][zj], copy3[1 - zi][zj]);

                if(!present.count(copy3))
                {
                    q.push(copy3);
                    present.insert(copy3);
                }
            }

            moves++;
        }
    };

    bfs();

    if(present.count(solved))
        cout << moves << endl;

    else
        cout << -1 << endl;


}

