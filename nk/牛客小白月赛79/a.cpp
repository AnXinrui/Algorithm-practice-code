#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n) {
		if (n % 2 == 0)
			break;
		n /= 10;
		++ cnt;
	}
	cout << cnt;
	
	return 0;
}
