#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int inf = 1e18;
int dp[1 << 20];
int n, maxWeight;
vector<int> weight;
int sumWeight[1 << 20];

int calculate(int mask)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & mask)
            sum += weight[i];
    }
    return sum;
}

void cal()
{
    for (int i = 0; i < (1 << n) ; i++)
        sumWeight[i] = calculate(i);
}

int solve(int mask)
{
    if (mask == 0)
        return 0;

    if (dp[mask] != inf)
        return dp[mask];

    int ans = 1e17;
    for (int submask = mask; submask != 0; submask = mask & (submask - 1))
    {
        if (sumWeight[submask] <= maxWeight)
            ans = min(ans, 1 + solve(mask ^ submask));
    }
    return dp[mask] = ans;
}
int32_t main()
{
    cin >> n >> maxWeight;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        weight.push_back(temp);
    }
    cal();

    for (int i = 0; i < (1 << n); i++)
        dp[i] = inf;

    cout << solve((1 << n) - 1);
    return 0;
}
