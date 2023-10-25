#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e3 +9;

int n, h, r;

struct node
{
    LL x, y, z;
}node[N];

int p[N];
void init() {
    for (int i = 0; i <= n + 1; i ++)
        p[i] = i;
}

int find(int k) {
    if (p[k] != k)
        p[k] = find(p[k]);
    return p[k];
}

// 距离平方
LL distance_square(struct node a, struct node b) {
    LL ans = (LL)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    // cout << ' ' << ans << endl;
    return ans;
}

void Union(int a, int b) {
    int u = find(a), v = find(b);
    if (u != v)
        p[u] = v;
}


/*
    并查集
    入口(第0层)为结点0， 出口(第h层)为节点n+1
    判断p[0] ? p[n+1]
*/
signed main()
{
    int t;
    cin >> t;
    while (t --) {
        cin >> n >> h >> r;
        init();
        for (int i = 1; i <= n; i ++)
            cin >> node[i].x >> node[i].y >> node[i].z;
        for (int i = 1; i <= n; i ++) {
            if (node[i].z - r <= 0)
                Union(0, i);
            if (node[i].z + r >= h)
                Union(i, n + 1);
            for (int j = i + 1; j <= n; j ++) {
                if (distance_square(node[i], node[j]) <= (LL)4 * r * r)
                    Union(i, j);
            }
        }
        // for (int i = 0; i <= n + 1; i ++)
        //     cout << p[i] << ' ';
        // cout << endl;
        if (find(0) == find(n+1))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}