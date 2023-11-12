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

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(k);
    for (int i = 0; i < k; i ++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int sco = 0;
    for (int i = 0; i < k; i ++)
    {
        if (m >= n * a[i])
        {
            m -= n * a[i];
            sco += n;
        }
        else if (m < n * a[i]) {
            // int j = 1;
            // cout << m << a[i];
            while (m - a[i] >= 0) {
                m -= a[i];

                sco ++;
            }
            cout << sco;
            return 0;
        }
        if (!m) break;
    }
    cout << sco;

    return 0;
}


