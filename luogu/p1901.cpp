#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int h[N], v[N];
int ans[N];
int stk[N], tt;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) 
		cin >> h[i] >> v[i];
	for (int i = 1; i <= n; i ++) {
		while (tt && h[stk[tt]]<= h[i])
			tt --;
		if (tt)
			ans[stk[tt]] += v[i];
		stk[++ tt] = i;
	}
	tt = 0;
	for (int i = n; i > 0; i --) {
		while (tt && h[stk[tt]] <= h[i])
			tt --;
		if (tt)
			ans[stk[tt]] += v[i];
		stk[++ tt] = i;
	}
	cout << *max_element(ans, ans + n + 1);
	
	return 0;
}
