#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> m;
    int ans = -1, start = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(a[i]) != m.end())
        {
            ans = max(ans, i - start);

            if (start > m[a[i]])
                start = start;
            else
            {
                start = m[a[i]] + 1;
            }
            // cout << ans << endl;
        }
        m[a[i]] = i;
    }
    ans = max(ans, n - start);
    cout << ans;
    return 0;
}
