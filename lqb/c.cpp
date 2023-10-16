#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;
int q;

bool check(int m) {
    int cnt = 0;
    int sm = 0;
    vector<int> v;
    for (int i = 1; i <= n; i ++) {
        if (sm == 0 ) {
            // ++ cnt;
            sm = a[i];
        }
        if (sm != 0 && a[i] - sm > m) {
            sm = a[i];
            cnt ++;
        }

    }
   ++ cnt;
    return cnt <= q;
}

int main() {

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = a[n] - a[1];
    while (l < r) {
        // cout << l << ' '<<r<<endl;
        int m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;

    }
    cout << l;

    return 0;
}