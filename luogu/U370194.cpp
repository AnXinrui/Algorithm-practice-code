#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	int s = a - 'A' + b - 'A';
	string ans = "";
	if (s == 0){
		cout <<'A';
		return 0;
	}
	while (s) {
		char c = 'A' + (s % 26);
//		cout << c;
		ans = c + ans;
		s /= 26;
	}
	cout << ans;
//	cout << ('A' + 2);
	return 0;
}
