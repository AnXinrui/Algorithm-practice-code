#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int c[5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    while (n --) {
        int i;
        cin >> i;
        ++ c[i];
    }
    ans += c[4];
    ans += c[2] / 2;
    c[2] %= 2;

    if (c[3] >= c[1]) {
        ans += c[3] + c[2];
        cout << ans << endl;
    }
    else {
        ans += c[3];
        c[1] -= c[3];
        if (c[2]) {
            ans += 1;
            c[1] = max(0, c[1] - 2);
        }
        if (c[1])
            ans += (c[1] + 3) / 4;
        cout << ans << endl;
    }
    return 0;
}


