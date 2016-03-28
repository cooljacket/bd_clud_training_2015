#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std; 

void display(const vector<int>& v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << endl;
}

vector<int> gen(int size, int MAX = 20) {
	vector<int> v;
	for (int i = 0; i < size; ++i)
		v.push_back(rand() % MAX);
	return v;
}

void insertionSort(vector<int>& v) {
	for (int cur = 1; cur < v.size(); ++cur) {
		int now = v[cur], index = cur-1;
		while (index >= 0 && now < v[index]) {
			v[index+1] = v[index];
			--index;
		}
		v[index+1] = now;
		cout << "cur = " << cur << ": ";
		display(v);
	}
}

int main() {
	srand(time(NULL));
	vector<int> v(gen(7));
	display(v);
	insertionSort(v);
	return 0;
}