#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    int flag = 0;
    if (a == 1) {
        if ((n - 1) % b == 0)
            flag = 1;
    }
    else {
        LL num = 1;
        while (num <= n) {
            // cout <<'*'<<num;
            if ((n - num) % b == 0) {
                flag = 1;
                break;
            }

            num *= a;
        }
    }
    if (flag)   puts("Yes");
    else    puts("No");
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


