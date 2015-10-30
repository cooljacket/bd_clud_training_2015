// 试试想想如果棋子有障碍，该怎么办？下学期讲搜索会来解答，你们也可以自己先去学bfs和dfs等图论的内容
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, d;
	char beg[3], end[3];
	cin >> n;

	while(n--) {
		cin >> beg >> end;
		int disX = abs(beg[0] - end[0]), disY = abs(beg[1] - end[1]);

		if (disX == 0 && disY == 0) {
			cout << "0 0 0 0" << endl;
			continue;
		}

		cout << max(disX, disY) << ' ';		// 王的步数

		// 后的步数
		if (disX == disY || beg[0] == end[0] || beg[1] == end[1])
			cout << 1 << ' ';
		else cout << 2 << ' ';

		// 车的步数
		if ((beg[0] == end[0]) || (beg[1] == end[1]))
			cout << 1 << ' ';
		else cout << 2 << ' ';

		// 象的步数
		if (disX % 2 != disY % 2)
			cout << "Inf" << endl;
		else if (disX == disY)
			cout << 1 << endl;
		else cout << 2 << endl;
	}

	return 0;
}