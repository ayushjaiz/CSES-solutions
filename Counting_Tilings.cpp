#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

void generate_next_masks(int idx, int next_mask, int n, vector<int> &next_masks, int current_mask)
{
    if (idx == n + 1)
    {
        next_masks.push_back(next_mask);
        return;
    }

    if ((current_mask & (1 << idx)) != 0)
        generate_next_masks(idx + 1, next_mask, n, next_masks, current_mask);

    else
    {
        if (idx != n and (current_mask & (1 << (idx + 1))) == 0)
            generate_next_masks(idx + 2, next_mask, n, next_masks, current_mask);

        generate_next_masks(idx + 1, next_mask + (1 << idx), n, next_masks, current_mask);
    }
}

int dp[1005][1 << 11];
int fun(int col, int mask, const int m, const int n)
{
    if (col == m + 1)
        return mask == 0;

    if (dp[col][mask] != -1)
        return dp[col][mask];

    vector<int> next_masks;
    generate_next_masks(1, 0, n, next_masks, mask);

    int ans = 0;
    for (auto next_mask : next_masks)
        ans += fun(col + 1, next_mask, m, n), ans %= mod;

    return dp[col][mask] = ans;
}

int32_t main()
{
    memset(dp, -1, sizeof(dp));

    int m, n;
    cin >> n >> m;

    cout << fun(1, 0, m, n);
    return 0;
}
