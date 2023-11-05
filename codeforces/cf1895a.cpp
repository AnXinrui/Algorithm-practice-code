#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (x >= y)
        cout << x << endl;
    else {
        int c = y - x;
        c = max(0, c - k);
        cout << y + c << endl;
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


