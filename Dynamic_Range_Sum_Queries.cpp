#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void build(ll a[], ll s, ll e, ll *tree, ll index)
{
    if (s == e)
    {
        tree[index] = a[s]*1LL;
        return;
    }
    ll mid = (s + e) / 2;

    build(a, s, mid, tree, 2 * index);
    build(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = tree[2 * index]+ tree[2 * index + 1];
}
ll query(ll left, ll right, ll index, ll *tree, ll s, ll e)
{
    if (left <= s && e <= right)
        return tree[index];

    if (e < left || right < s)
        return 0LL;

    ll mid = (s + e) / 2;
    ll op1 = query(left, right, 2 * index, tree, s, mid);
    ll op2 = query(left, right, 2 * index + 1, tree, mid + 1, e);

    return op1+op2;
}
void updatePoint(ll index, ll tree[], ll s, ll e, ll increment, ll point)
{
    if (e < point || point < s)
        return;

    if (s == e)
    {
        tree[index] = increment;
        return;
    }

    ll mid = (s + e) / 2;
    updatePoint(2 * index, tree, s, mid, increment, point);
    updatePoint(2 * index + 1, tree, mid + 1, e, increment, point);

    tree[index] = tree[2 * index] + tree[2 * index + 1];
}
int main()
{
    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll *tree = new ll[4 * n + 1];
    for (ll i = 1; i < 2 * n + 1; i++)
        tree[i] = 1e6;

    build(a, 0, n - 1, tree, 1);

    ll left, right, k,pos,final;
    while (q--)
    {
        cin >> k;
        if (k == 1)
        {
            cin >> pos >> final;
            updatePoint(1, tree, 0, n - 1, final, pos-1);
        }
        else
        {
            cin >> left >> right;
            --left, --right;
            cout << query(left, right, 1, tree, 0, n - 1) << endl;
        }
    }
}
