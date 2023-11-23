#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const double pi = 3.1415926535;
int n;
double xx1, yy1, xx2, yy2, x[1010], y[1010];
double dist[1010][1010], R[1010];
int st[1010];
double ans;

void dfs(int cnt, double square) {
	if (cnt == n) {
		ans = max(ans, square);
		return;
	} 
	for (int i = 1; i <= n; i ++) {
		if (st[i])	continue;
		double r = min(min(xx2 - x[i], x[i] - xx1), min(yy2 - y[i], y[i] - yy1));
		for (int j = 1; j <= n;  ++j) 
			if (st[j]) 
				r = min(r, dist[i][j] - R[j]);
		if (r < 0)	r = 0;	
		R[i] = r;
		st[i] = 1;
		dfs(cnt + 1, square + pi * r * r);
		st[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	xx1 = min(a, c), xx2 = max(a, c);
	yy1 = min(b, d), yy2 = max(b, d);
	for (int i = 1; i <= n; i ++) 
		scanf("%lf%lf", &x[i], &y[i]);
	
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])),
			dist[j][i] = dist[i][j];
	
	dfs(0, 0.0);
	
	double res = (xx2 - xx1) * (yy2 - yy1) - ans;
	printf("%.0lf", res);
	
	return 0;
}

