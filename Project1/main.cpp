#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{	
	char n, m;
	string tmp;
	fstream file;
	file.open("1.data", ios::in);
	while (!file.eof()) {
		getline(file, tmp);
		cout << tmp << endl;
	}
	return 0;
}