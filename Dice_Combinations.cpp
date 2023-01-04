#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb emplace_back
#define endl "\n"
#define uii unordered_map<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vl vector<long long int>
#define pii pair<int, int>
#define si set<int>
#define ff first
#define ss second
#define mp make_pair
#define imax INT_MAX
#define imin INT_MIN
#define yes cout << "YES"
#define no cout << "NO"
#define pno cout << -1
#define alice cout << "ALICE"
#define bob cout << "BOB"
#define zz cout << 0

#define ceild(a, b) ceil(a * 1.0 / b) // a is divided by b
#define ceil2(n) (n & 1) + (n >> 1)
#define odd(i) i & 1
#define even(i) !(i & 1)
#define rev greater<int>()
#define lb lower_bound
#define ub upper_bound
#define setpr(x) cout << setprecision(x) << fixed
#define setbits(x) __builtin_popcountll(x)
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define yrn(condition) cout << (condition ? "YES" : "NO")
const int mod = 1e9 + 7;

#define fl(i, a, b) for (int i = a; i <= b; ++i)
#define rl(i, a, b) for (int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define asize(a) sizeof(a) / sizeof(a[0])
#define vsort(v) sort(v.begin(), v.end())
#define asort(a) sort(a, a + asize(a))
#define amax(a) *max_element(a, a + asize(a))
#define amin(a) *min_element(a, a + asize(a))
#define vmax(a) *max_element(a.begin(), a.end())
#define vmin(a) *min_element(a.begin(), a.end())
#define vprint(v)     \
    for (auto it : v) \
    cout << it << " "
#define aprint(a)                      \
    for (int i = 0; i < asize(a); i++) \
    cout << a[i] << " "
//
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
//------------------------------------------------------->  BY AYUSH

void solve()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    a[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll d = 1; d <=6; d++)
        {
            if (i - d >= 0)
            sum = (sum + a[i - d]) % mod;
        }
        a[i] = sum;
    }
    cout << a[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
   // cin >> testcases;
    while (testcases--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
// i*j vector---> vector<vector<int>> mat(i, vector<int>(j, 0));
