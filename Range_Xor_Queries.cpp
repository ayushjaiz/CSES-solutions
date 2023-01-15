#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void build(int a[], int s, int e, int *tree, int index)
{
    if (s == e)
    {
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;

    build(a, s, mid, tree, 2 * index);
    build(a, mid + 1, e, tree, 2 * index + 1);

    tree[index] = tree[2 * index] ^ tree[2 * index + 1];
}
int query(int left, int right, int index, int *tree, int s, int e)
{
    if (left <= s && e <= right)
        return tree[index];

    if (e < left || right < s)
        return 0;

    int mid = (s + e) / 2;
    int op1 = query(left, right, 2 * index, tree, s, mid);
    int op2 = query(left, right, 2 * index + 1, tree, mid + 1, e);

    return op1 ^ op2;
}
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int *tree = new int[4 * n + 1];
    for (int i = 1; i < 2 * n + 1; i++)
        tree[i] = 0;

    build(a, 0, n - 1, tree, 1);

    // updatePoint(1, tree, 0, n - 1, +10, 1);
    // updateRange(1, tree, 0, n - 1, +10, 1, 1);

    // for (int i = 1; i <= 2 * n + 1; i++)
    //     cout << tree[i] << " ";

    int left, right;
    while (q--)
    {
        cin >> left >> right;
        --left, --right;
        cout << query(left, right, 1, tree, 0, n - 1) << endl;
    }
}
