#include <iostream>

using namespace std;


const int N = 1e5 + 10;
int p[N], d[N], sz[N];
int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }

    return p[x];
}
int main() {
    for (int i = 0; i < 30010; i ++) {
        p[i] = i;
        sz[i] = 1;
    }

    int T;
    cin >> T;
    while (T --) {
        char op;
        int i, j;
        cin >> op >> i >> j;
        if (op == 'M') {
            int u = find(i), v=find(j);
            if (u != v) {
                p[u] = v;
                d[u] += sz[v];
                sz[v] += sz[u];
            }
        }
        else {
            int u = find(i), v = find(j);
            // cout << d[u] << d[v] << endl;
            if (u != v)
                puts("-1");
            else
                cout << max(0, abs(d[i]-d[j])-1);
        }
    }
    return 0;
}