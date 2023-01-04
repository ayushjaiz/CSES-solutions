//               JAI SHREE RAM

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb emplace_back
#define endl "\n"
#define uii unordered_map<int, int>
#define mii map<int, int>
#define vi vector<int>
#define reverse greater<int>()
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define odd(i) i & 1
#define even(i) !(i & 1)
#define yes cout << "YES"
#define no cout << "NO"
#define all(v) v.begin(), v.end()
#define ceil(n) (n & 1) + (n >> 1)
#define maxinarray(a) *max_element(a, a + n)
#define mininarray(a) *min_element(a, a + n)
#define maxinvector(a) *max_element(a.begin(), a.end())
#define mininvector(a) *min_element(a.begin(), a.end())
#define printvector(v) \
    for (auto it : v)  \
    cout << it << " "
#define printarray(a)           \
    for (int i = 0; i < n; i++) \
    cout << a[i] << " "
const int M = 1e9 + 7;
//------------------------------------->BY AYUSH
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);

    sort(b, b + m);
    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= d)
        {
            count++;
            i++;
            j++;
        }
        if (a[i] + d < b[j])
            i++;
        else if (a[i] - d > b[j])
            j++;
    }
    cout << count;
    //...//
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcases = 1;
    while (testcases--)
    {
        solve();
        cout << endl;
    }
}
