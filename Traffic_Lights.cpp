#include <bits/stdc++.h>
#define ll long long int
#define vprint(v)     \
    for (auto it : v) \
    cout << it << " "
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    int a[q];
    for (int i = 0; i < q; i++)
        cin >> a[i];

    set<int> v;
    multiset<int> res;
    res.insert(n);
    v.insert(0);
    v.insert(n);
    for (int i = 0; i < q; i++)
    {
        auto high = v.upper_bound(a[i]);
        auto low = prev(high);
        v.insert(a[i]);

        int k = *high - *low;
        res.erase(res.find(k));
        res.insert(*high - a[i]);
        res.insert(a[i] - *low);
        cout << *res.rbegin() << " ";
    }
    return 0;
}
