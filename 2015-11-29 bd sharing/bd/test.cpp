#include <iostream>
using namespace std;

int main() {
	int a[100];
	cout << sizeof(a) / sizeof(int) << endl;
	return 0;
}

# select
5 13 7 2 8

5 8 7 2 13

5 2 7 8 13

5 2 7 8 13

2 5 7 8 13



# insert
5 13 7 2 8

5
5 13
5 7 13
2 5 7 13
2 5 7 8 13