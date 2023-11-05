#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    int tmp = n;
    int ans = 0;
    for (int i = 2; i <= n; i ++)
        ans += a[i] - a[i-1] + a[tmp + i] - a[tmp+i-1];
    cout << ans << endl;

    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ' << a[tmp + i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t --)
        solve();

    return 0;
}

/*
10 10 20

20 30 30

*/
