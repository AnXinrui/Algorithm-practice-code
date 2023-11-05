#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL x;
    cin >> x;
    LL l = 0, r = 14;
    while (l < r) {
        LL m = (l+r)/2;
        LL tmp = pow(m, m);
        if (tmp < x)
            l = m + 1;
        else
            r = m;
    }
    if (pow(l,l) == x)
        cout << l << endl;
    else
        puts("-1");

    return 0;
}


