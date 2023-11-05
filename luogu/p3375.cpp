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
	scanf("%s%s", s + 1, p + 1);
	n = strlen(p + 1);
	m = strlen(s + 1);
	
	// next array 
	for (int i = 2, j = 0; i <= n; i ++) {
		while (j && p[i] != p[j + 1])	
			j = ne[j];
		if (p[i] == p[j + 1]) {
			j ++;
			ne[i] = j;
		}
	}
	
	// kmp
	for (int i = 1, j = 0; i <= m; i ++) {
		while (j && s[i] != p[j + 1])
			j = ne[j];
		if (s[i] == p[j + 1])
			j ++;
		if (j == n)
			cout << i - n + 1 << endl;
	}
	
	for (int i = 1; i <= n; i ++)
		cout << ne[i] << ' ';
		
	return 0;
}

