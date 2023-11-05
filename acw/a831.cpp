#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e6 + 10;

int n, m, ne[N];
char p[N], s[N];

int main() {
	cin >> n >> p + 1 >> m >> s + 1;
	for (int i = 2, j = 0; i <= n; i ++) {
		while (!j && p[i] != p[j + 1])
			j = ne[j];
		if (p[i] == p[j + 1])
		{
			j ++;
			ne[i] = j;
		}
		cout <<j;
	}
	for (int i = 1, j = 0; i <= m; i ++) {
		while (!j && p[i] != p[j + 1])
			j = ne[j];
		if (p[i] == p[j + 1]) {
			j ++;
		}
		if (j == n) 
			cout << i - n << ' ';
	}
	return 0;
}

