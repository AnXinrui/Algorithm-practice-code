#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//h表示第i位同学的idx是多少，e表示这个点的值是多少，l表示这个点左边的点的编号，r表示这个点右边的点的编号 
int h[N], e[N], l[N], r[N], idx;

void init() {
	// 0号点表示左端点，1号点表示右端点
	r[0] = 1;
	l[1] = 0; 
	idx = 2;
}

// 在节点a（编号）的左边插入一个数x idx也是编号
void insert_l(int a, int x) {
	e[idx] = x;
	r[idx] = a;
	l[idx] = l[a];
	r[l[a]] = idx;
	l[a] = idx;
	h[x] = idx ++;
}

//在节点a（编号）的右边插入一个数x idx也是编号
void insert_r(int a, int x) {
	e[idx] = x; //先在idx记录这个值 
    l[idx] = a; //左边是a
    r[idx] = r[a]; //右边是r[a]
    l[r[a]] = idx; //让原来a的右边的数的左边变为idx
    r[a] = idx; //a的右边 
    h[x] = idx ++;
}

void remove(int a) {
	r[l[a]] = r[a];
	l[r[a]] = l[a];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	int n;
	cin >> n;
	
	init();
	insert_r(0, 1);
	
	for (int i = 2; i <= n; i ++) {
		int k, p;
		cin >> k >> p;
		if (p) 
			insert_r(h[k], i);
		else 
			insert_l(h[k], i);
	}

	int m;
	cin >> m;
	
	while (m --) {
		int x;
		cin >> x;
		
		if (h[x] != -1) {
			remove(h[x]);
			h[x] = -1;
		}
			
	}
	
	for (int i = r[0]; i != 1; i = r[i])
		cout << e[i] << ' ';
		
	return 0;
} 
