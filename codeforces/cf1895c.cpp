#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int p[6][50];
vector<string> ss;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < t; i ++) {
        string s;
        cin >> s;
        ss.push_back(s);

        int sum = 0, n = s.size();
        for (int j = 0; j < n; j ++) {
            sum += s[j] - '0';
            // p[j+1][sum] ++;
        }
        p[n][sum] ++;
        // sum = 0;
        // for (int j = n - 1; j >= 0; j --) {
        //     sum += s[j] - '0';
        //     e[n-j][sum] ++;
        // }
    }

    for (int i = 0; i < t; i ++) {
        string s = ss[i];
        int n = s.size();

        vector<int> a(n + 1);
        for (int j = 0; j < n; j ++) {
            int v = s[j] - '0';
            a[j+1] = a[j] + v;
        }
        ans += p[n][a[n]];
        for (int j = 0; j < n; j ++) {
            int pre = a[j+1], ed = a[n] - a[j+1];
            // if ((j + 1 > n - j - 1) && pre > ed) {
            //     ans += p[j+1-(n-j-1)][pre-ed];
            // }
            if ((j + 1 < n - j - 1) && pre < ed) {
                ans += p[n-(j+1)*2][ed-pre];
            }
            else if ((j + 1 > n - j - 1) && pre > ed) {
                ans += p[j+1-(n-j-1)][pre-ed];

            }

        }
        ans --;
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}

/*
10 10 20

20 30 30

*/
