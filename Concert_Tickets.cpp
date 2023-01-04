#include <bits/stdc++.h>
using namespace std;
int n, m, t, k;
multiset<int> ticket;
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        ticket.insert(k);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        auto match = ticket.upper_bound(t);
        if (match == ticket.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--match) << endl;
            ticket.erase(match);
        }
    }
    //...//
}
int main()
{
    solve();
    return (0);
}
