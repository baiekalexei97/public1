#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream F1(argv[1]);
	vector<float> quad;
	float fl;
	while (F1 >> fl) {
		quad.push_back(fl);
	}
	quad.push_back(quad[0]);
	quad.push_back(quad[1]);

	ifstream F2(argv[2]);
	float s;
	vector<float> dots;
	while (F2 >> s) {
		dots.push_back(s);
	}

	for (int i = 0; i < dots.size(); i += 2) {
		int dot = -1;
		for (int j = 0; j < 8; j += 2) {
			if (dots[i] == quad[j] && dots[i + 1] == quad[j + 1])
				dot = 0;
		}
		if (dot == 0) {
			cout << "0\n";
			continue;
		}
		for (int j = 0; j < 8; j += 2) {
			long double ax = dots[i] - quad[j];
			long double ay = quad[j + 3] - quad[j + 1];
			long double bx = quad[j + 2] - quad[j];
			long double by = dots[i + 1] - quad[j + 1];
			long double d1 = ax * ay;
			long double d2 = bx * by;
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
	return 0;
}
