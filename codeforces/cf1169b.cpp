#include <iostream>

using namespace std;
const int N = 3e5 + 10;
int st1[N], st2[N];
int n, m, s1, s2, s3, s4;

int main() {
	cin >> n >> m;
	int a, b;
	cin >> a >> b;
	s1=1,s3=1;
	for (int i = 1; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		if (x == a || a == y)	++ s1;
		else
			s2 = max(++ st1[x], ++ st1[y]);
		if (x == b || y == b)	++ s3;
		else
			s4 = max(++ st2[x], ++ st2[y]);
//		cout << s1 << ' '<<s2<<' '<<s3<<' '<<s4<<endl;
	}
	if (s1 + s2 == m || s3 + s4 == m)
		puts("YES");
	else	puts("NO");
	return 0;
} 
