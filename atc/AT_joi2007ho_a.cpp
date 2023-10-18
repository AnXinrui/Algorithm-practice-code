#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N];
int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for (int i = e; i <= n; i ++) {
        ans = max(ans, a[i] - a[i-e]);
    }
    cout << ans << endl;
    return 0;
}