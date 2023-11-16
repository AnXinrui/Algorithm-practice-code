#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int son[N * 30][2], cnt, v[N];
int n;
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int p, int u, int sum) {
    v[u] = sum;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == p) continue;
        dfs(u, j, sum ^ w[i]);
    }
}

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++ cnt;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (son[p][!u])
            res = res * 2 + !u,
            p = son[p][!u];
        else
            res = res * 2 + u,
            p = son[p][u];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int u, v, c;
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }

    dfs(-1, 1, 0);

    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
        insert(v[i]);
        res = max(res, v[i] ^ query(v[i]));
    }

    cout << res << "\n";

    return 0;
}


