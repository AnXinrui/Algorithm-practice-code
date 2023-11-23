#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int N = 105;

int m, st[N][N], maze[N][N], val[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

/* 情况： a后面是b 
	a = 1， b = 1; a = 0, b = 0        t = 0
	a = 1, b = 0; a = 0, b = 1 -> val+=1   t = 0
	a = 1, b = -1; a = 0, b = -1    -> b = 1/0, val+=2, t = 1
	a = 1/0 && t = 1 (b == -1 continue;   b != -1 , a = a0, val
*/ 
int main() {
	memset(maze, -1, sizeof maze);
	memset(val, 0x3f, sizeof val);
	int n;
	cin >> m >> n;
	while (n --) {
		int a, b, c;
		cin >> a >> b >> c;
		maze[a][b] = c;
	}
	
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	st[1][1] = 1;
	val[1][1] = 0;
	// t = 1 表示上一次用过魔法 
	int t = 0;
	while (!q.empty()) {
		int x = q.front().frist, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > 0 && ny > 0 && nx <= m && ny <= m) {
				st[nx][ny] = 1;
				if (maze[nx][ny] == maze[x][y] && !t && maze[nx][ny] != -1) {
					if (val[nx][ny] > val[x][y])
						q.emplace(nx, ny); 					
				}
				else if (!t && maze[nx][ny] != maze[x][y] && maze[nx][ny] != -1 && maze[x][y] != -1) {
					if (val[nx][ny] > val[x][y] + 1)
						q.emplace(nx, ny); 
				}
				else if (!t && maze[nx][ny] == -1 && maze)
			}
		}
	}
}
 
