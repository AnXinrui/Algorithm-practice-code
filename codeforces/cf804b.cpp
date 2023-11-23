#include <iostream>
#include <string>

const int mod = 1e9 + 7;

int main() {
	std::string s;
	std::cin >> s;
	long long ans = 0, cnt = 0;
	for (int i = s.size() - 1; ~i; i --) {
		if (s[i] == 'b')
			cnt ++;
		else
			ans = (ans + cnt) % mod,
			cnt = cnt * 2 % mod;
	}
	std::cout << ans << "\n";
	return 0;
}
