#include <bits/stdc++.h>
using namespace std;

/*------------ayushjaiz------------*/

int mod = 1e9 + 7;
#define int long long int
int change(int sum, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int j = 0; j <= sum; j++)
        if (j % coins[0] == 0)
            dp[0][j] = 1;

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= sum; t++)
        {
            int nottake = dp[i - 1][t];

            int take = 0;
            if (coins[i] <= t)
                take = dp[i][t - coins[i]];

            dp[i][t] = (take + nottake) % mod;
        }
    }
    return dp[n - 1][sum];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << change(sum, a);
    return 0;
}