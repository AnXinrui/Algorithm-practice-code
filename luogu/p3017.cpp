#include <iostream>

using namespace std;

int a[1010][1010], s[1010][1010];
int r, c, x, y;

bool check(int m) {
    int lrow = 0;
    int rows = 0;
    for (int i = 1; i <= r; i ++) {
        int num = 0, sum = 0;
        for (int j = 1; j <= c; j ++) {
            if (sum + (s[i][j]-s[i][j-1])-(s[lrow][j]-s[lrow][j-1]) < m)
                sum += (s[i][j]-s[i][j-1])-(s[lrow][j]-s[lrow][j-1]);
            else {
                sum = 0;
                num ++;
            }
        }
        if (num >= y) {
            lrow = i;
            ++ rows;
        }

    }
    return rows >= x;
}

int main() {

    cin >> r >> c >> x >> y;
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= c; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    int left = 0, right = s[r][c];
    //m 越小越容易成功
    while (left < right) {
        int m = left + right + 1 >> 1;
        if (check(m))
            left = m;
        else
            right = m - 1;
    }
    cout << left;

    return 0;
}