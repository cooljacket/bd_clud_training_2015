#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const bool DEAD = false, LIVING = true;
const int dir[9][2] = {	{-1, -1}, {-1, 0}, {-1, 1}, 
						{0, -1}, 			{0, 1},
						{1, -1}, {1, 0},  {1, 1}};

class LifeGame{
	vector<vector<bool> > world;
	int size, numOfLivingCell;

public:
	LifeGame(int size) {
		this->size = size;
		numOfLivingCell = 0;
		world = vector<vector<bool> >(size, vector<bool>(size));
		srand(time(0));
		double dead_p = 0.5;
		int MAX = 9997;
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				if ((rand()%MAX)*1.0/MAX < dead_p)
					world[i][j] = DEAD;
				else {
					world[i][j] = LIVING;
					++numOfLivingCell;
				}
	}

	void display() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j)
				if (world[i][j] == DEAD)
					cout << ' ';
				else
					cout << 'O';
			cout << endl;
		}
	}

	void change() {
		vector<vector<bool> > copy(world);
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j) {
				int count = 0;
				for (int k = 0; k < 9; ++k) {
					int x = (i + dir[k][0] + size) % size;
					int y = (j + dir[k][1] + size) % size;
					if (copy[x][y] == LIVING)
						++count;
				}

				if (copy[i][j] == DEAD && count == 3) {
					world[i][j] = LIVING;
					++numOfLivingCell;
				}
				if (copy[i][j] == LIVING && (count > 3 || count < 2)) {
					world[i][j] = DEAD;
					--numOfLivingCell;
				}
			}
	}

	bool isEnd() {
		return numOfLivingCell == 0;
	}
};


int main() {
	LifeGame game(20);

	game.display();
	while (!game.isEnd()) {
		game.change();
		sleep(1);
		system("cls");
		game.display();
	}	
	return 0;
}