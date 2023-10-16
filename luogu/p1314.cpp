#include <iostream>

using namespace std;

#define I return
#define LOVE 0
#define LXT ;

const int N = 2e5 + 10;

int w[N], v[N], le[N], ri[N];
long long pre_cnt[N], pre_val[N];
int l, r;

// 注意long long
int main() {
	int n, m;
	long long s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> w[i] >> v[i];
		// w + 1 为了取 w大于所有值的情况
		r = max(r, w[i] + 1);
	}
	for (int i = 1; i <= m; i ++)
		cin >> le[i] >> ri[i];

	long long ans = 0x3f3f3f3f3f3f3f3f;
	// 我们要清楚，二分的之后目标值附近的值都可以被扫描到
	while (l < r) {
		int mid = l + r >> 1;
		// mid 即 W, W 越大 y 越小
		// 前缀和
		for (int i = 1; i <= n; i ++) {
			if (w[i] >= mid) {
				pre_cnt[i] = pre_cnt[i-1] + 1;
				pre_val[i] = pre_val[i-1] + v[i];
			}
			else {
				pre_val[i] = pre_val[i-1];
				pre_cnt[i] = pre_cnt[i-1];
			}
		}

		long long y = 0;
		for (int i = 1; i <= m; i ++)
			y += (pre_cnt[ri[i]] - pre_cnt[le[i]-1]) * (pre_val[ri[i]] - pre_val[le[i]-1]);
		long long t = s - y;
		if (t >= 0)
			r = mid;
		else
			l = mid + 1;
		ans = min(ans, llabs(t));
	}
	cout << ans;

	I LOVE LXT;
}