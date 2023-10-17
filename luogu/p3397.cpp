#include <iostream>

using namespace std;

int a[1010][1010], b[1010][1010];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2+1] -= c;
    b[x2+1][y1] -= c;
    b[x2+1][y2+1] += c;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2, 1);
    }
    // a是前缀和
    // a[i][j] = a[i-1][j]+a[i][j-1]+-a[i-1][j-1]+b[i][j]
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}