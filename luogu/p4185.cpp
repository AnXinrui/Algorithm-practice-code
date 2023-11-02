#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct node
{
    int p, q, r;
}a[N];

struct query {
    int k, v, idx;
}que[N];

int ans[N];
int p[N], c[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void Union(int x, int y) {
    int u = find(x), v = find(y);
    if (u != v) {
        p[u] = v;
        c[v] += c[u];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n-1; i ++)
        cin >> a[i].p >> a[i].q >> a[i].r;
    for (int i = 1; i <= q; i ++) {
        cin >> que[i].k >> que[i].v;
        que[i].idx = i;
    }

    for (int i = 1; i <= n ; i ++) {
        p[i] = i;
        c[i] = 1;
    }
    sort(a + 1, a + n, [](node &a, node &b) {
        return a.r > b.r;
    });
    sort(que + 1, que + 1 + q, [](query &a, query &b) {
        return a.k > b.k;
    });
    

    
    int j = 1;
    for (int i = 1; i <= q; i ++) {
        while (que[i].k <= a[j].r && j <= n-1) {
            Union(a[j].p, a[j].q);
            j ++;
        }
        ans[que[i].idx] = c[find(que[i].v)];
        
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] - 1 << endl;

    return 0;
}


