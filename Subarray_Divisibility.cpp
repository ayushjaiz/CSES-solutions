#include <bits/stdc++.h>
using namespace std;

/*------------ayushjaiz------------*/

#define int long long int

int subarraysDivByK(vector<int> &a, int k)
{
    vector<int> s(k, 0);
    int psum = 0, ans = 0;
    s[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        psum = (psum + (a[i] % k) + k) % k;
        ans += s[psum];
        s[psum]++;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << subarraysDivByK(a, n);
}
