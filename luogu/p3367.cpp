#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int f[N];


int main() {
    int n, m;
    cin >> n >> m;
    function<int(int)> find = [&](int a)->int {
        if (f[a] == a)      return a;
        return f[a] = find(f[a]);
    };
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    while (m--) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            f[find(x)] = find(y);
        }
        else {
            if (find(x) == find(y)) 
                puts("Y");
            else 
                puts("N");
        }
    }
    return 0;
}

