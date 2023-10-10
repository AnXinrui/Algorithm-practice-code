#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main() {
    int n, m;
    cin >> n >> m;
    int r = 0;
    for (int i = 0; i < n; i ++) {
    	cin >> a[i];
    	r += a[i];
	} 
        
    int l = *max_element(a, a + n);
    while (l < r) {
        int mid = (l + r >> 1);
        int p = 0, cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i] + p > mid) {
                cnt ++;
                p = 0;
            }
            p += a[i];
        }
        cnt ++;
        if (cnt > m)
            l = mid + 1;
        else    r = mid;
    }
    cout << l;

    return 0;
}


// 4 3 3
