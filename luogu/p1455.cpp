#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int p[N], c[N], v[N], st[N], f[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i ++)
    {
        cin >> c[i] >> v[i];
        p[i] = i;
    }
    while (m --) {
        int a, b;
        cin >> a >> b;
        int x = find(a), y = find(b);
        if (x != y) {
            p[x] = y;
            c[y] += c[x];
            v[y] += v[x];
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (find(i) == i) {
            for (int j = w; j >= c[i]; j --) {
                f[j] = max(f[j], f[j-c[i]] + v[i]);
            }
        }
    }
    
    cout << f[w];
    return 0;
}