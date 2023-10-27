#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//h��ʾ��iλͬѧ��idx�Ƕ��٣�e��ʾ������ֵ�Ƕ��٣�l��ʾ�������ߵĵ�ı�ţ�r��ʾ������ұߵĵ�ı�� 
int h[N], e[N], l[N], r[N], idx;

void init() {
	// 0�ŵ��ʾ��˵㣬1�ŵ��ʾ�Ҷ˵�
	r[0] = 1;
	l[1] = 0; 
	idx = 2;
}

// �ڽڵ�a����ţ�����߲���һ����x idxҲ�Ǳ��
void insert_l(int a, int x) {
	e[idx] = x;
	r[idx] = a;
	l[idx] = l[a];
	r[l[a]] = idx;
	l[a] = idx;
	h[x] = idx ++;
}

//�ڽڵ�a����ţ����ұ߲���һ����x idxҲ�Ǳ��
void insert_r(int a, int x) {
	e[idx] = x; //����idx��¼���ֵ 
    l[idx] = a; //�����a
    r[idx] = r[a]; //�ұ���r[a]
    l[r[a]] = idx; //��ԭ��a���ұߵ�������߱�Ϊidx
    r[a] = idx; //a���ұ� 
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
