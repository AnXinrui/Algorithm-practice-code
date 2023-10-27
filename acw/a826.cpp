#include <iostream>

using namespace std;

const int N = 1e5 + 10;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
int e[N], ne[N], idx;
int head;

void init() {
    head = -1;
}

void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void del(int k) {
    ne[k-1] = ne[ne[k-1]];
}

void ins(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k-1];
    ne[k-1] = idx ++;
}

int main() {
    init();
    int m;
    cin >> m;
    while (m --) {
        char s;
        int x, k;
        cin >> s;
        if (s == 'H') 
        {
            cin >> x;
            add_to_head(x);
        }
        else if (s == 'D')
        {
            cin >> k;
            // 第k个插入的数idx=k-1，当k=0时，看题目
            if (!k)     head = ne[head];
            else    del(k);
        }
        else {
            cin >> k >> x;
            ins(k, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    
    return 0;
}