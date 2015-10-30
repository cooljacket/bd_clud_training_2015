#include <iostream>
using namespace std;

bool tumor[105][105];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	int n, tmp, area = 0, perimeter = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			if (tmp <= 50) {
				tumor[i][j] = true;
				++area;
			}
		}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!tumor[i][j])
				continue;
			for (int k = 0; k < 4; ++k) {
				int x = i + dir[k][0], y = j + dir[k][1];
				if (!tumor[x][y]) {
					++perimeter;
					break;
				}
			}
		}
	}

	cout << area << ' ' << perimeter << endl;

	return 0;
}