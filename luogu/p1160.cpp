#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
// 超时
int main() {
    int n;
    cin >> n;
    a.push_back(1);
    for (int i = 2; i <= n; i ++) {
        int k, p;
        cin >> k >> p;
        if (p == 1)
            a.insert(find(a.begin(), a.end(), k) + 1, i);
        else
            a.insert(find(a.begin(), a.end(), k), i);

    }

    int m;
    cin >> m;
    while (m --) {
        int x;
        cin >> x;
        if (find(a.begin(), a.end(), x) != a.end())
            a.erase(find(a.begin(), a.end(), x));
    }
    for (auto i: a)
        cout << i<<' ';
    return 0;
}




#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

struct node
{
    // l,r是idx
    int l = -1, r = -1, v = -1;
}a[N];

int h[N], idx;
int head;

void init() {
    a[idx].v = 1;
    head = idx;
    h[1] = idx ++;
}

void add_to_right(int k, int i) {
    int j = h[k];
    a[idx].v = i;
    int q = a[j].r;
    a[idx].r = q;
    if (q != -1)
        a[q].l = idx;
    a[j].r = idx;
    a[idx].l = j;
    h[i] = idx ++;
}

void add_to_left(int k, int i) {
    int j = h[k];
    a[idx].v = i;
    int q = a[j].l;
    a[idx].l = q;
    if (q!=-1)
        a[q].r = idx;
    a[j].l = idx;
    a[idx].r = j;
    if (head == j)
        head = idx;
    h[i] = idx ++;

}

void remove(int i) {
    if (h[i] == -1)
        return;
    int j = h[i];
    h[i] = -1;
    int ll = a[j].l, rr = a[j].r;
    if (ll != -1)
        a[ll].r = rr;
    if (rr != -1)
        a[rr].l = ll;
}

// 丑陋的双链表，自己都觉得丑陋
int main() {


    init();

    int n;
    cin >> n;
    for (int i = 2; i <= n; i ++) {
        int k, p;
        cin >> k >> p;
        if (p == 1)
            add_to_right(k, i);
        else
            add_to_left(k, i);
        // for (int j = 0; j < idx; j ++) {
        //     cout << a[j].v << ' '<<a[j].l << ' '<<a[j].r << endl;
        // }
        // cout << head<<endl;
    }

    // for (int i = h[head]; i != -1; i = a[i].r) {
    //     cout << a[i].v << ' ';
    // }

    int m;
    cin >> m;
    while (m --) {
        int i;
        cin >> i;
        remove(i);

    }
    for (int i = head; i != -1; i = a[i].r) {
        cout << a[i].v << ' ';
    }
    cout << endl;

    return 0;
}

//  2 3 4 1