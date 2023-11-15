#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 4e4;

int a[N+10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    a[0] = 1;
    for (int i = 1; i <= N; i ++)
    {
        string s = to_string(i);
        if (s == string(s.rbegin(), s.rend())) {
            for (int j = i; j <= N; j ++)
                a[j] += a[j-i];
        }
    }

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        cout << a[n] << "\n";
    }

    return 0;
}


