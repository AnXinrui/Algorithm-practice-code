#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

// ’‚ «œÛ∆Â 
int dx[8] = {1, 2, -1, -2, -1, -2, 1, 2}, dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int n, m, x, y;
int c[500][500];

void bfs() {
	queue<PII> q;
	memset(c, -1, sizeof c);
	c[x][y] = 0;
	q.push({x, y});
	while (!q.empty()) {
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i ++) 
		{
			int nx = xx + dx[i], ny = yy + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && c[nx][ny] == -1) {
				c[nx][ny] = c[xx][yy] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	cin >> n >> m >> x >> y;
	bfs();
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}

