#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int t = 0;
    for (int i = 1; i < n; i ++) {
        if (s[i] == 'a' && s[i-1] == 'b' || s[i] == 'b' && s[i-1] == 'a') {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}


