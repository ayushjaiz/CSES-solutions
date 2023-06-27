#include <bits/stdc++.h>
using namespace std;

vector<int> sieve() // primes till n
{
    int i, j;
    int n = 1000 + 10;
    vector<int> a(n + 1, 0), ans;
    for (int i = 3; i <= n; i += 2)
        a[i] = 1;
    a[2] = 1;
    for (i = 3; i * i <= n; i = i + 2)
    {
        for (j = i * i; j <= n; j += 2 * i)
            if (a[j])
                a[j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        if (a[i])
            ans.emplace_back(i);
    }
    return ans;
}
void l(int m, vector<int> &primes)
{
    int i = 0;
    int res = 1;

    while (primes[i] * primes[i] <= m)
    {
        if (m % primes[i] == 0)
        {
            int count = 0;
            while (m % primes[i] == 0)
            {
                count++;
                m = m / primes[i];
            }
            res *= count + 1;
        }
        i++;
    }
    if (m != 1)
        res *= 2;

    cout << res << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> primes = sieve();
    int testcases = 1, temp;
    cin >> testcases;
    while (testcases--)
    {
        cin >> temp;
        l(temp, primes);
    }
    return 0;
}
