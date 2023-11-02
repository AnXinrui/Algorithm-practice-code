#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N], d[N];
int n, k;

void init() {
    for (int i = 1; i <= n; i ++)
        p[i] = i;
}

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main() {
    // 1代表吃 它的父节点， 0代表和父亲是同一类
    cin >> n >> k;
    int ans = 0;
    init();
    while (k --) {
        int nu, x, y;
        cin >> nu >> x >> y;
        if (x > n ||  y > n)
            ans ++;
        else
        {
            int px = find(x), py = find(y);
            if (nu == 1) {
                if (px == py && (d[x] - d[y]) % 3)
                    ans ++;
                else if (px != py) {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else {
                if (px == py && px == py && (d[x] - d[y] - 1) % 3)
                    ans ++;
                else if (px != py) {
                    p[px] = p[y];
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }

    }
    cout << ans;

    return 0;
}