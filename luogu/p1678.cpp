#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i ++) 
		cin >> a[i];
	sort(a + 1, a + 1 + m);
	// long long 
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		// res ��ʾÿ��ѧ���Ĳ����� 
		int res;
		int stu;
		cin >> stu; 
		int l = 1, r = m;
		while (l < r) {
			int mid = (l + r) >> 1;			
			if (a[mid] < stu)	l = mid + 1;
			else 	r = mid;
		}
		
		// stu������Ԥ��¼ȡ������С 
		if (l == 1)		res = a[1] - stu;
		// abs��Ϊ����������Ԥ��¼ȡ�������� ����� 
		else 	res = min(abs(a[l] - stu), stu - a[l - 1]);
		ans += res;	

	}
	cout << ans;
	
	return 0;
}















