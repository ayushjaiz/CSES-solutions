#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> c(n), dp(x, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= x; i++)
    {
        int ways = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] < 0)
                continue;
            ways = (ways + dp[i - c[j]]) % mod;
        }
        dp[i] = ways;
    }
    cout << dp[x];
    return 0;
}