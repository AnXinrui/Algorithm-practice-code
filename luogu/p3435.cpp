#include <iostream>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;

char s[N];
LL ne[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> s + 1;
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j+1])
            j ++;
        ne[i] = j;
    }
    LL ans = 0;
    for (int i = 2; i <= n; i ++) {
        int j = i;
        while (ne[j]) {
            j = ne[j];
        }
        if (ne[i])  ne[i] = j;
        ans += i-j;
    }
    cout << ans << endl;

    return 0;
}