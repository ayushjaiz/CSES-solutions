#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, a, b;
    cin >> n;
    vector<ll> p(n);
    ll sum = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> b;
        sum += b;
        p[i] = a;
    }
    sort(p.begin(), p.end(), greater<ll>());

    for (ll i = 0; i < n; i++)
    {
        ans += (i + 1) * p[i];
    }
    cout << sum - ans;
    return 0;
}
