#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int a[N];
int q[N], hh, tt = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout << 0x3f3f3f3f;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		while (hh <= tt && q[hh] <= i - k)
			hh ++;
		while (hh <= tt && a[q[tt]] >= a[i]) 
			tt --;
		q[++ tt] = i;
		if (i >= k)
			cout <<a[q[hh]]  << ' ';
	}
	cout << endl;
	hh = 0, tt = -1;
	for (int i = 1; i <= n; i ++) {
		while (hh <= tt && q[hh] <= i - k)
			hh ++;
		while (hh <= tt && a[q[tt]] <= a[i]) 
			tt --;
		q[++ tt] = i;
		if (i >= k)
			cout << a[q[hh]] << ' ';
	}
	cout << endl;
	return 0;
}
