#include <bits/stdc++.h>
using namespace std;

#define int long long int

int dp[20][10][2][2];
int fun(string s, int idx = 0, int prev = 0, int tight = 1, bool leading = false)
{
    if (idx == s.length())
        return 1;

    if (dp[idx][prev][tight][leading] != -1)
        return dp[idx][prev][tight][leading];

    int digit = s[idx] - '0';
    int limit = tight ? digit : 9;
    int ans = 0;

    for (int curr = 0; curr <= limit; curr++)
    {
        if (curr == prev and leading == true)
            continue;

        if (leading == false and curr == 0)
            ans += fun(s, idx + 1, curr, tight == 1 & curr == digit, 0);

        else
            ans += fun(s, idx + 1, curr, tight == 1 & curr == digit, 1);
    }
    return dp[idx][prev][tight][leading] = ans;
}
int count(int low, int high)
{
    memset(dp, -1, sizeof(dp));
    int L = fun(to_string(low - 1));

    memset(dp, -1, sizeof(dp));
    int R = fun(to_string(high));

    // cout << L << " " << R<<endl;

    return (low == 0) ? R : R - L;
}

int32_t main()
{
    int a, b;
    cin >> a >> b;

    cout << count(a, b);

    return 0;
}