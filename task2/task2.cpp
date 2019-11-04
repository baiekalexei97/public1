#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream F1(argv[1]);
	vector<float> quad;
	float fl;
	while (F1 >> fl) {
		quad.push_back(fl);
	}
	F1.close();
	quad.push_back(quad[0]);
	quad.push_back(quad[1]);

	ifstream F2(argv[2]);
	float x, y;
	while (!F2.eof()) {
		F2 >> x >> y;
		int dot = -1;
		for (int j = 0; j < 8; j += 2) {
			if (x == quad[j] && y == quad[j + 1])
				dot = 0;
		}
		if (dot == 0) {
			cout << "0\n";
			continue;
		}
		for (int j = 0; j < 8; j += 2) {
			long double ax = x - quad[j];
			long double by = quad[j + 3] - quad[j + 1];
			long double bx = quad[j + 2] - quad[j];
			long double ay = y - quad[j + 1];
			long double d1 = ax * by;
			long double d2 = bx * ay;
			long double d = d1 - d2;
			if (d == 0.0) {
				dot = 1;
				continue;
			}
			if (d < 0.0) {
				dot = 3;
				break;
			}
		}
		if (dot == 1) {
			cout << "1\n";
		}
		else if (dot == 3) {
			cout << "3\n";
		}
		else
			cout << "2\n";
	}
	F2.close();
	return 0;
}
