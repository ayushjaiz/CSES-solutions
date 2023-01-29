#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool pos(ll x, ll a[], ll t, ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += x / a[i];
        if (sum >= t)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, t;
    cin >> n >> t;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, r = 1e18, res;
    sort(a, a + n);

    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (pos(mid, a, t, n))
        {
            r = mid - 1;
            res = mid;
        }
        else
            l = mid + 1;
    }
    cout << res;
    return 0;
}
// i*j vector---> vector<vector<int>> mat(i, vector<int>(j, 0));
