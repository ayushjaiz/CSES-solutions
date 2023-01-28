#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define vprint(v) for (auto it : v) cout << it << " "

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<pair<pair<int, int>, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].ss = i;
    }
    sort(p.begin(), p.end());

    multimap<int, int> m;
    m.insert({p[0].ff.ss, 1});
    int id = 1;
    ans[p[0].ss] = 1;

    for (int i = 1; i < n; i++)
    {
        if (m.begin()->first < p[i].ff.ff)
        {
            auto it = m.begin();
            m.insert({p[i].ff.ss, it->ss});

            ans[p[i].ss] = it->ss;
            m.erase(it);
        }
        else
        {
            m.insert({p[i].ff.ss, ++id});
            ans[p[i].ss] = id;
        }
    }
    cout << id << endl;
    vprint(ans);
}
