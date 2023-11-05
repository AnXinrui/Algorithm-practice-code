#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;


void solve() {
    LL a, b;
    cin >> a >> b;
    LL l = round(pow(a*b), 1.0/3);

    if (l * l * l == tmp)
        puts("Yes");
    else
        puts("No");
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


// x^2*y x*y^2   x^3 y^3