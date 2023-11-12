#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    array<int, 30> f{};
    for (int i = 0; i < 30; i ++)
        f[i] = 1 << i;
    while (q --) {
        int x;
        cin >> x;
        for (int i = 0; i < 30; i ++)
            if (f[i] % (1 << x) == 0)
                f[i] += 1 << (x-1);
    }
    for (int i = 0; i < n; i++) {
        int k = __builtin_ctz(a[i]);
        a[i] += f[k] - (1 << k);
        cout << a[i] << " \n"[i == n - 1];
    }
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


