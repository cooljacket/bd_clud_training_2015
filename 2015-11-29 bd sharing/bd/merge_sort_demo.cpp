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

void mergeSortHelper(vector<int>& v, int left, int right) {
	if (right <= left)
		return ;

	int mid = (left + right) / 2;
	mergeSortHelper(v, left, mid);
	mergeSortHelper(v, mid+1, right);
	vector<int> sorted;
	int minN = v[left], L_index = left, R_index = mid + 1;
cout << "LEft: " << left << ' ' << right << ' ' << mid << endl;
display(v);
	while (L_index <= mid && R_index <= right) {
		if (L_index <= mid && v[L_index] < v[R_index])
			sorted.push_back(v[L_index++]);
		else
			sorted.push_back(v[R_index++]);
	}
	if (L_index <= mid)
		while (L_index <= mid)
			sorted.push_back(v[L_index++]);
	if (R_index <= right)
		while (R_index <= right)
			sorted.push_back(v[R_index++]);
cout << "sorted: ";
display(sorted);
	for (int i = 0; i < sorted.size(); ++i)
		v[left+i] = sorted[i];
display(v);
cout << endl;
}

void mergeSort(vector<int>& v) {
	mergeSortHelper(v, 0, v.size()-1);
}

int main() {
	srand(time(NULL));
	vector<int> v(gen(7));
	display(v);
	mergeSort(v);
	return 0;
}