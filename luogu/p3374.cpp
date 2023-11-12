#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int v;
        cin >> v;
        add(i, v);
    }
    while (m --) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
            add(a, b);
        else
            cout << query(b) - query(a - 1) << endl;
    }

    return 0;
}