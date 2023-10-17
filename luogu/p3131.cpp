#include <iostream>

using namespace std;
const int N = 5e4 + 5;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++) {
            int s = a[j] - a[i-1];
            if (s % 7 == 0 && j - i + 1 > ans)
                ans = j - i + 1;
        }
    cout << ans;

    return 0;
}