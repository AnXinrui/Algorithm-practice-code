#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

PII a[N];

// q1维护最大值(递减)  q中存储序号 
int q1[N], q2[N];
int h1 = 1, h2 = 1, t1, t2;
int ans = 0x3f3f3f3f;

int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + n);
	
	for (int l = 1, r = 0; l <= n; l ++) {
		while (h1 <= t1 && q1[h1] < l)		h1 ++;
		while (h2 <= t2 && q2[h2] < l)		h2 ++;
		
		while (a[q1[h1]].second - a[q2[h2]].second < d && r < n) {
			r ++;
			while (h1 <= t1 && a[q1[t1]].second < a[r].second)		t1 --;
			q1[++ t1] = r;
			while (h2 <= t2 && a[q2[t2]].second > a[r].second)		t2 --;
			q2[++ t2] = r;	
		}
		
		if (a[q1[h1]].second - a[q2[h2]].second >= d)
			ans = min(ans, abs(a[q1[h1]].first - a[q2[h2]].first));
	
	}
    if (ans == 0x3f3f3f3f)
        cout << -1;
    else
        cout << ans;
	return 0;
}
