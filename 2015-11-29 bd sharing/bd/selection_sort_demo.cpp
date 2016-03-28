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

void selectionSort(vector<int>& v) {
	for (int tail = v.size()-1; tail > 0; --tail) {
		int maxNum = v[0], index = 0;
		for (int i = 1; i <=tail; ++i)
			if (v[i] > maxNum) {
				maxNum = v[i];
				index = i;
			}
		swap(v[index], v[tail]);
		cout << "Tail = " << tail << ": ";
		display(v);
	}
}

int main() {
	srand(time(NULL));
	vector<int> v(gen(7));
	display(v);
	selectionSort(v);
	return 0;
}