#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N], v[N], le[N], ri[N];
// c 表示 [l,r] 符合要求的个数， p表示 [l,r] 的价值和
int c[N], p[N];

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int l = 0, r = 0;
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> v[i];
        r = max(r, a[i]);
    }
    for (int i = 1; i <= m; i ++)
        cin >> le[i] >> ri[i];
	
    // 二分, 找出y值大于等于s的数
    while (l < r) {

        // W
        int mid = l + r >> 1;
        for (int i = 1; i <= n; i ++) {
            if (a[i] >= mid) {
                c[i] = 1;
                p[i] = v[i];
            }
            else {
                c[i] = 0;
                p[i] = 0;
            }
            // 前缀和
            c[i] += c[i - 1];
            p[i] += p[i - 1];
        }
//        cout << mid << endl;
//		for (int i = 1; i <= n; i ++) {
//			cout << c[i] << ' ' << p[i] << endl;
//		}

        int y = 0;
        for (int i = 1; i <= m; i ++) {
            y += (p[ri[i]] - p[le[i]-1]) * (c[ri[i]] - c[le[i]-1]);
//            cout << ' '<<y<<endl;
        }
        int t = s - y;
        if (t >= 0)  r = mid;
        else {
        	l = mid + 1;
//        	cout << l << endl;
		} 
        cout <<mid << ' '<< abs(t)<<endl;   
        res = min(res, abs(s - y));
    }
    cout << res;

    return 0;
}
