#include <iostream>
#include <queue>

using namespace std;

int e[150], head, ne[250];

// ����1 
void init() {
	head = -1;
	e[1] = 1;
	ne[1] = head;
	head = 1;
}


int main() {
	int n, m;
	cin >> n >> m;
	
	init();
	for (int i = 2; i <= n; i ++) {
		e[i] = i;
		ne[i] = ne[i - 1];
		ne[i - 1] = i;
	}
	// ѭ������ 
	ne[n] = head;
	
	// c ��¼δ��Ȧ������ c ��¼��ǰ�����ڼ����� 
	int c = n, cnt = 0;
	queue<int> ans;
	int i = head;
	while (c) {
		++ cnt;
		if (cnt == m - 1) {
			ans.push(e[ne[i]]);
			-- c;
			ne[i] = ne[ne[i]];
			cnt = 0;
		}
		i = ne[i];
	}
	
	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
	
	return 0;
} 
