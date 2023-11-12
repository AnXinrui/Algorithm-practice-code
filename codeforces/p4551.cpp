#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int n;
int h[N], e[N], ne[N], idx, val[N];
// 入度
int d[N];

void add(int a, int b, int w) {
    e[idx] = b;
    ne[b] = h[a];
    h[a] = idx ++;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int a, b, w;
        cin >> a >> b >> w;
    }

    return 0;
}


