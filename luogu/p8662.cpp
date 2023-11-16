#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1010;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char g[N][N];
int st[N][N];
int n, cnt1, cnt2;

void dfs(int i, int j) {
	st[i][j] = 1;
	for (int k = 0; k < 4; k ++) {
		int ni = i + dx[k], nj = j + dy[k];
		if (!st[ni][nj] && g[ni][nj] != '.')
			dfs(ni, nj);
	}
}

// 先 dfs 判断有几个岛， 然后再进行淹没过程， 再判断几个岛 
int main() {
	
	cin >> n; 
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> g[i][j];
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (g[i][j] == '#' && !st[i][j]) {
				++ cnt1;
				dfs(i, j);
			} 
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (g[i][j]=='#' && (g[i-1][j] == '.' || g[i+1][j] == '.' ||
			g[i][j-1] == '.' || g[i][j+1] == '.'))
			{
 				g[i][j] = '-';
			} 
		}
	}
	memset(st, 0, sizeof st);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (g[i][j] == '#' && !st[i][j]) {
				++ cnt2;
				dfs(i, j);
			} 
		}
	}
//	cout << cnt1 << ' ' << cnt2 << endl;
	
	cout << max(cnt1 - cnt2, 0) << endl;
	
	return 0;
}

