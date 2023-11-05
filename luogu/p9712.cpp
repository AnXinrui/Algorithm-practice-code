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
//32    cout << int('a'-'A');
    string s;
    cin >> s;
    for (char &i: s) {
        if (i >= 'A' && i <= 'Z')
            i += 32;
        if (i == '_')
            i = '-';
    }
    s = "solution-" + s;
    cout << s;

    return 0;
}


