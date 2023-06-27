#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int exp(int a, int b) // a^b
{
    int ans = 1;
    while (b)
    {
        if (b & 1LL)
            ans = (ans * 1LL * a) % mod;
        a = (a * 1LL * a) % mod, b = b >> 1LL;
    }
    return ans;
}
int inverse(int a, int b = mod) { return exp(a, b - 2); }

int mul(int a, int b) { return (((a % mod * 1ll * b % mod) % mod) + mod) % mod; }
int add(int a, int b) { return (((a % mod * 1LL + b % mod) % mod) + mod) % mod; }
int sub(int a, int b) { return (((a % mod * 1LL - b % mod) % mod) + mod) % mod; }
int divide(int a, int b) { return (((a % mod * 1ll * exp(b, mod - 2)) % mod) + mod) % mod; }

int till(int n)
{
    return divide(mul(n, sub(n, 1)), 2);
}
int32_t main()
{
    int n;
    cin >> n;
    int sum = 0;
    int i = 1;
    while (i <= n)
    {
        int times = n / i;
        int next_i = (n / times) + 1;

        int rangesumtill_next_i_minus1 = till(next_i);
        int rangesumtill_i_minus1 = till(i);

        sum += mul(times, sub(rangesumtill_next_i_minus1, rangesumtill_i_minus1));
        sum %= mod;
        i = next_i;
    }
    cout << sum << endl;
    return 0;
}