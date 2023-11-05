#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i <= n + 7; i ++)
        p[i] = i;
    while (m --) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n || y > n) {
            ++ ans;
            continue;
        }
        int u = find(x), v = find(y);
        if (t == 1) {
            if (u == v && (d[x] - d[y]) % 3)
                ++ ans;
            else if (u != v){
                p[u] = v;
                d[u] = d[y] - d[x];
            }
        }
        else {
            if (x == y) {
                ++ ans;
                continue;
            }
            if (u == v && (d[x] - d[y] - 1) % 3)
                ++ ans;
            else if (u != v){
                p[u] = v;
                d[u] = d[y] + 1 - d[x];
            }
        }
//        cout << ans ;
    }
    cout << ans;

    return 0;
}


