#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int a[N];

/*
	注意二分的写法
	注意精度 
*/
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int l = 0, r = *max_element(a + 1, a + n + 1);
    while (l < r) {
        int mid = (long long)(l + r + 1) / 2;
        long long s = 0;
        for (int i = 1; i <= n; i ++) {
            if (mid < a[i])   s += a[i] - mid;
        }
        if (s < m)      r = mid - 1;
        else    l = mid;
    }
    cout << l;

    return 0;
}
