#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int h[N], e[N], ne[N], val[N], idx, d[N];

int n, ans;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void dfs(int he, int s) {
    // cout << he <<' '<<s<<' '<<h[he]<<endl;
    int i = h[he];
    if (i == -1) {
        ans = max(ans, s);
        return;
    }

    for (; i != -1; i = ne[i]) {
        int j = e[i];
        int v = val[j];
        dfs(j, s ^ v);
    }
    // cout << head << ' ' << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i ++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b);
        val[b] = w;
        ++ d[b];
    }
    int head;
    for (int i = 1; i <= n; i ++)
        if (!d[i])
        {
            head = i;
            break;
        }
    // for (int i = 0; i <= idx; i ++)
    //     cout << i << ' '<<h[i]<<' '<<e[i]<<' '<<ne[i]<<endl;
    for (int i = h[head]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j, val[j]);
    }
    cout << ans;

    return 0;
}


