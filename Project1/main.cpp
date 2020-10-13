#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{	
	char m, n;
	string tmp;
	fstream ff;
	ff.open("1.data");
	while (!ff.eof()) {
		ff.getline(tmp, 10);
		cout << tmp;
	}
	ff.close();
	return 0;
}