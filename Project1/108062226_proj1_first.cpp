#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 建立二維陣列
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
			a[0][0] = a[0][1] = a[0][2] = a[1][1] = 1;
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
			a[0][1] = a[1][0] = a[1][1] = a[1][2] = 1;
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
			a[0][0] = a[1][0] = a[2][0] = a[2][1] = 1;
		}
		else if (s == "L2") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 1;
			first_block[2] = 1;
			a[0][0] = a[0][1] = a[0][2] = a[1][0] = 1;
		}
		else if (s == "L3") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 2;
			first_block[1] = 0;
			a[0][0] = a[0][1] = a[1][1] = a[2][1] = 1;
		}
		else if (s == "L4") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][2] = a[1][0] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "J1") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			a[0][1] = a[1][1] = a[2][0] = a[2][1] = 1;
		}
		else if (s == "J2") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][0] = a[1][0] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "J3") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 2;
			a[0][0] = a[0][1] = a[1][0] = a[2][0] = 1;
		}
		else if (s == "J4") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 1;
			a[0][0] = a[0][1] = a[0][2] = a[1][2] = 1;
		}
		else if (s == "S1") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 0;
			first_block[2] = 1;
			a[0][1] = a[0][2] = a[1][0] = a[1][1] = 1;
		}
		else if (s == "S2") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			a[0][0] = a[1][0] = a[1][1] = a[2][1] = 1;
		}
		else if (s == "Z1") {
			row = 2;
			col = 3;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
			first_block[1] = 0;
			first_block[2] = 0;
			a[0][0] = a[0][1] = a[1][1] = a[1][2] = 1;
		}
		else if (s == "Z2") {
			row = 3;
			col = 2;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 0;
			first_block[1] = 1;
			a[0][1] = a[1][0] = a[1][1] = a[2][0] = 1;
		}
		else if (s == "I1") {
			row = 4;
			col = 1;
			a = mal(row, col);
			first_block = new int[col];
			first_block[0] = 1;
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
		for (int i = 0; i < row; i++) {
			delete[] a[i];
		}
		delete[] a;
		delete[] first_block;
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

	void put_tetris(Case c){
		bool hit = false;
		int current_row = 0;
		int current_col = c.idx;
		for (current_row = 0; current_row < this->row - 1; current_row++) {
			for (int j = 0; j < c.col; j++) {
				if (c.first_block[j] > current_row) continue;
				else if (this->a[current_row + 1 - c.first_block[j]][current_col + j] == 1) {
					hit = true;
				}
			}
			if (hit) break;
		}
	}

	int ** a;
	int row, col;
};



int main(int argc, char *argv[])
{	
	string tmp;
	fstream fin, fout;

	// read in the data
	fin.open("1.data", ios::in);
	fout.open("108062226_proj1.final", ios::out);
	char m_char = fin.get();
	char trash = fin.get(); // 把空格讀掉
	char n_char = fin.get();
	char trash2 = fin.get(); // 把換行讀掉
	int m = m_char - '0';
	int n = n_char - '0';
	Matrix map(m, n);

	while (!fin.eof()) {
		string s;
		fin >> s;
		if (s == "End") break;

		int idx, step;
		fin >> idx >> step;
		idx--;
		step--;
		Case(s, idx, step);
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