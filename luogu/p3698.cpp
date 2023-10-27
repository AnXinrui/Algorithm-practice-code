#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;

PII a[N];

// q1表示最大的数， q2表示最小的数  的 序号
int q1[N], hh1, tt1 = -1;
int q2[N], hh2, tt2 = -1;

int ans = 0x3f3f3f3f;

int main() {
    int n, d;
    cin >> n >> d;

    for (int i = 0; i < n; i ++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n);
    cout << "----------------------------"<<endl;
//    for (int i = 0; i < n; i ++)
//    	if (a[i].second >= 400)
//		cout << a[i].first << ' ' << a[i].second << endl; 

    for (int l = 0, r = -1; l < n; l ++) {
        while (hh1 <= tt1 && q1[hh1] < l)  ++hh1;
        while (hh2 <= tt2 && q2[hh2] < l)  ++hh2;

        while (a[q1[hh1]].second - a[q2[hh2]].second < d && r < n-1)
        {
            ++ r;
            while (hh1 <= tt1 && a[q1[hh1]].second < a[r].second)
                tt1 --;
            q1[++ tt1] = r;
            while (hh2 <= tt2 && a[q2[hh2]].second > a[r].second)
                tt2 --;
            q2[++ tt2] = r;

        }

        if (a[q1[hh1]].second - a[q2[hh2]].second >= d)
            ans = min(ans, abs(a[q1[hh1]].first-a[q2[hh2]].first));
        cout << a[q1[hh1]].first << ' ' << a[q1[hh1]].second << endl;
        cout << a[q2[hh2]].first << ' ' << a[q2[hh2]].second << endl;
        cout << ans << endl;
        cout << endl;
    }

    if (ans == 0x3f3f3f3f)
        cout << -1;
    else
        cout << ans;
    return 0;
}
