/* @ayushjaiz */

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define endl "\n"
using uii = unordered_map<int, int>;
using mii = map<int, int>;
using vi = vector<int>;
using pii = pair<int, int>;
using si = set<int>;
#define ff first
#define ss second
#define mp make_pair
#define nl cout << "\n"
#define yes cout << "YES "
#define no cout << "NO "
#define pno cout << -1 << " "
#define alice cout << "ALICE "
#define bob cout << "BOB "
#define zz cout << 0 << " "
#define dbg(var) cout << #var << "=" << var << " "
using maxheap = priority_queue<int>;
using minheap = priority_queue<int, vector<int>, greater<int>>;

#define ceild(a, b) (a + b - 1) / b // a is divided by b
#define ceil2(n) (n + 1LL) >> 1LL
#define odd(i) i & 1
#define even(i) !(i & 1)
#define rev greater<int>()
#define lb lower_bound
#define ub upper_bound
#define setpr(x) cout << setprecision(x) << fixed
#define setbits(x) __builtin_popcountll(x)
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define yrn(condition) cout << (condition ? "YES " : "NO ")
const int mod = 1e9 + 7;

#define fo(i, a, b) for (int i = a; i < b; ++i)
#define fl(i, a, b) for (int i = a; i <= b; ++i)
#define rl(i, a, b) for (int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vmax(a) *max_element(a.begin(), a.end())
#define vmin(a) *min_element(a.begin(), a.end())

void vprint(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
int vsum(vector<int> &v)
{
    int sum = 0;
    for (auto it : v)
        sum += it;
    return sum;
}
vector<int> psum(vector<int> &v)
{
    vector<int> ans(0, v.size() + 1);
    for (int i = 0; i < v.size(); i++)
        ans[i + 1] = ans[i] + v[i];
    return ans;
}

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};
int dx8[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy8[] = {0, 0, -1, 1, 1, 1, -1, -1};

// NUMBERS

int countdigits(int n)
{
    int s = 0;
    while (n != 0)
    {
        s++;
        n = n / 10;
    }
    return s;
}

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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int lowpowerof2(int n) { return 1LL << (int)log2(n); }
int highpowerof2(int n) { return 1LL << (int)ceil(log2(n)); }
bool ispowerof2(int n) { return (n != 0) && ((n & (n - 1)) == 0); }
int inverse(int a, int b) { return exp(a, b - 2); }

int mul(int a, int b) { return (((a % mod * b % mod) % mod) + mod) % mod; }
int add(int a, int b) { return (((a % mod + b % mod) % mod) + mod) % mod; }
int sub(int a, int b) { return (((a % mod - b % mod) % mod) + mod) % mod; }
int divide(int a, int b) { return (((a % mod * 1ll * exp(b, mod - 2)) % mod) + mod) % mod; }

// STRING

int issubstring(string &s1, string &s2) // s1 is present in s2?
{
    if (s2.find(s1) != string::npos)
        return true; // s2.find(s1)
    return false;    // -1
}
bool ispalindrome(string &s)
{
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return (s1 == s);
}
string decimaltobinary(int n)
{
    string s;
    while (n)
        s += (n & 1LL) + '0', n = n >> 1LL;
    reverse(s.begin(), s.end());
    return s;
}
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)

void solve();
int dp[10000][2];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "\nCase " << i << ":\n";
        solve();
        cout << endl;
    }
    return 0;
}
// sir ek baar aur ques padhlo
// testcase bhi banalo apne please please
int fun(int width, int height)
{
    if (height <= 0)
        return 1;

    if (dp[height][width] != -1)
        return dp[height][width];

    if (width == 2)
    {
        int sum = 0;
        for (int i = 1; i <= height; i++)
        {
            sum += add(fun(2, height - i),0);
            sum %= mod;
        }
        for (int i = 0; i <= height; i++)
        {
            sum += fun(1, height - i), sum %= mod;
        }
        return dp[height][width] = sum;
    }
    else if (width == 1)
    {
        int sum = 0;
        for (int i = 1; i <= height; i++)
        {
            sum += fun(1, height - i), sum %= mod;
        }
        return dp[height][width] = sum;
    }
}
void solve()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fun(2, n);
}
