#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<int> v;
    v.insert(a[0]);
    for (int i = 1; i < n; i++)
    {
        auto it = v.upper_bound(a[i]);
        if (it != v.end())
            v.erase(it);
        v.insert(a[i]);
        // vprint(v);
        // cout << endl;
    }
    cout << v.size();
    return 0;
}
// i*j vector---> vector<vector<int>> mat(i, vector<int>(j, 0));
