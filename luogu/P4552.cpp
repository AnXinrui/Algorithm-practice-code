#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

void insert(int l, int r, int x) {
    b[l] += x;
    b[r + 1] -= x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        insert(i, i, a[i]);
    }
    // 整数、负数
    int pn = 0, nn = 0;
    for (int i = 2; i <= n; i ++) {
        if (b[i] > 0)
            pn += b[i];
        else if (b[i] < 0)
            nn += b[i];
    }
    int cnt = max(pn, -nn);
    int nums = abs(pn + nn) + 1;
    cout << cnt << endl << nums << endl;

    return 0;
}




