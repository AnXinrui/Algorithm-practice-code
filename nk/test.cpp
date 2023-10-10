#include <iostream>
#include <set>
using namespace std;

const int mod = 10e9 + 7;

int f(int x) {
	int res = 1;
	for (int i = 2; i <= x; i ++)
		res = (long long)res * i % mod;
	return res;
} 

int main() {
    string s;
    int k;
    cin >> s >> k;
    int num = 0;
	for (char c: s)
		if (c == '1')
			++ num;
	int ans = f(num) / (long long)f(k) * f(num - k) % mod;
	
	cout << ans;
    
    return 0;
}
