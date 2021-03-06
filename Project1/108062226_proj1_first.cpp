#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// �إߤG���}�C
int ** mal(int m, int n) {
	int **a;
	a = new int *[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) a[i][j] = 0;
	}
	return a;
}

class Case {
public:
	Case(string s, int IDX, int STEP) :idx(IDX), step(STEP), shape(s) {
		if (s == "T1") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			first_block[2] = 1;
			a[0][1] = a[1][0] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "T2") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			a[0][1] = a[1][0] = a[1][1] = a[2][1] = 1;
		}
		else if (s == "T3") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][0] = a[0][1] = a[0][2] = a[1][1] = 1;
		}
		else if (s == "T4") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 1;
			a[0][0] = a[1][0] = a[1][1] = a[2][0] = 1;
		}
		else if (s == "L1") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			a[0][0] = a[0][1] = a[1][0] = a[2][0] = 1;
		}
		else if (s == "L2") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 1;
			first_block[2] = 1;
			a[0][0] = a[1][0] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "L3") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 2;
			first_block[1] = 0;
			a[0][1] = a[1][1] = a[2][0] = a[2][1] = 1;
		}
		else if (s == "L4") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][0] = a[0][1] = a[0][2] = a[1][2] = 1;
		}
		else if (s == "J1") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			a[0][0] = a[0][1] = a[1][1] = a[2][1] = 1;
		}
		else if (s == "J2") { 
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][0] = a[0][1] = a[0][2] = a[1][0] = 1;
		}
		else if (s == "J3") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 2;
			a[0][0] = a[1][0] = a[2][0] = a[2][1] = 1;
		}
		else if (s == "J4") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 1;
			first_block[2] = 0;
			a[0][2] = a[1][0] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "S1") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 1;
			a[0][0] = a[0][1] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "S2") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			a[0][1] = a[1][0] = a[1][1] = a[2][0] = 1;
		}
		else if (s == "Z1") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][1] = a[0][2] = a[1][0] = a[1][1] = 1;
		}
		else if (s == "Z2") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 1;
			a[0][0] = a[1][0] = a[1][1] = a[2][1] = 1;
		}
		else if (s == "I1") {
			row = 4;
			col = 1;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			a[0][0] = a[1][0] = a[2][0] = a[3][0] = 1;
		}
		else if (s == "I2") {
			row = 1;
			col = 4;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			first_block[3] = 0;
			a[0][0] = a[0][1] = a[0][2] = a[0][3] = 1;
		}
		else if (s == "O") {
			row = 2;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			a[0][0] = a[0][1] = a[1][0] = a[1][1] = 1;
		}
	}
	~Case() {
	}

	int ** a;
	int row, col, idx, step;
	string shape;
	int *first_block; // first block of each column.
};

class Matrix {
public:
	Matrix(int m, int n) 
		: row(m), col(n) 
	{
		a = mal(m, n);
	};

	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete [] a[i];
		}
		delete [] a;
	}

	void show() {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				cout << this->a[i][j] << " ";
			}
			cout << endl;
		}
	}

	void put_tetris(Case c){
		bool hit = false;
		int current_row = 0;
		int current_col = c.idx;

		// fall down
		for (current_row = 0; current_row < this->row - 1; current_row++) {
			for (int j = 0; j < c.col; j++) {
				if (c.first_block[j] > current_row) continue;
				else if (this->a[current_row + 1 - c.first_block[j]][current_col + j] == 1) {
					hit = true;
				}
			}
			if (hit) break;
		}

		// move
		current_col += c.step;
		
		// if hit before, then fall down again
		if (hit) {
			hit = false; // reset
			for (current_row; current_row < this->row - 1; current_row++) {
				for (int j = 0; j < c.col; j++) {
					if (c.first_block[j] > current_row) continue;
					else if (this->a[current_row + 1 - c.first_block[j]][current_col + j] == 1) {
						hit = true;
					}
				}
				if (hit) break;
			}
		}

		// set the tetris block
		for (int i = 0; i < c.row; i++) {
			for (int j = 0; j < c.col; j++) {
				if(c.a[i][j] == 1) this->a[current_row - i][current_col + j] = 1;
			}
		}

		// Check if any line need to be disappear
		int row_need_to_check = this->row;
		int *disappear_row = new int[this->row];
		int checkRow = 0;
		while (checkRow != this->row) {
			disappear_row[checkRow] = 1;
			for (int j = 0; j < this->col; j++) {
				if (this->a[checkRow][j] == 0) disappear_row[checkRow] = 0;
			}
			if (disappear_row[checkRow]) {
				for (int i = checkRow; i >= 0; i--) {
					for (int j = 0; j < this->col; j++) {
						if (i == checkRow) {
							this->a[i][j] = 0;
						}
						else {
							this->a[i + 1][j] = this->a[i][j];
							this->a[i][j] = 0;
						}
					}
				}
			}
			checkRow++;
		}
	}

	int ** a;
	int row, col;
};



int main(int argc, char *argv[])
{	
	fstream fin, fout;
	// read in the data
	fin.open(argv[1], ios::in);
	fout.open("108062226_proj1.final", ios::out);
	int m, n;
	fin >> m >> n;
	Matrix map(m, n);

	while (1) {
		string s;
		fin >> s;
		if (s == "End") break;
		int idx, step;
		fin >> idx >> step;

		idx--;
		Case c(s, idx, step);
		map.put_tetris(c);
		//// things for testing
		//cout << "s = " << s << ", idx = " << ++idx << ", step = " << step << endl;
		//map.show();
	}

	// writing in 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			fout << map.a[i][j] << " ";
		}
		fout << map.a[i][n - 1] << endl;
	}
	fout.close();
	fin.close();
	return 0;
}