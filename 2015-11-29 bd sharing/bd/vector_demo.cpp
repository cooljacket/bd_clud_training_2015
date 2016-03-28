#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}

int main() {
	int len;
	cin >> len;
	vector<int> v1(len), v2(len, 6);
	display(v1);
	display(v2);

	v1[3] = 233;
	display(v1);

	for (int i = 1; i < 5; ++i)
		v2.push_back(i);
	display(v2);
	cout << "There are " << v2.size() << " elements in v2." << endl;

	return 0;
}