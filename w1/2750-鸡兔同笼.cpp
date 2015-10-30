#include <iostream>
using namespace std;

int main() {
	int n, num;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (num % 2 == 1) {
			cout << "0 0" << endl;
			continue;
		}
		int min = num / 4, max = num / 2;
		if (num % 4 != 0)
			++min;
		cout << min << ' ' << max << endl;
	}

	return 0;
}
/*
// 使用while循环可以这样写：

#include <iostream>
using namespace std;

int main() {
	int n, num;
	cin >> n;

	while(n--) {
		cin >> num;
		if (num % 2 == 1) {
			cout << "0 0" << endl;
			continue;
		}
		int min = num / 4, max = num / 2;
		if (num % 4 != 0)
			++min;
		cout << min << ' ' << max << endl;
	}

	return 0;
}
*/