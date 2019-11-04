#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	float s;
	vector<vector<float>> v(5);
	char* c = new char[255];
	char buff;
	for (int i = 1; i <= 5; i++) {
		buff = (char)(((int)'0') + i);
		strcpy(c, argv[1]);
		strcat(c, "\\Cash");
		strncat(c, &buff, 1);
		strcat(c,".txt");
		ifstream Cash(c);
		while (Cash >> s) {
			v[i-1].push_back(s);
		}
		Cash.close();
	}
	float max = 0.0;
	int maxp = 0;
	long double sum = 0.0;
	for (int i = 0; i < 16; i++) {
		sum = v[0][i]; 
		sum += v[1][i];
		sum += v[2][i];
		sum += v[3][i];
		sum	+= v[4][i];
		if (sum > max) {
			max = sum;
			maxp = i+1;
		}
		sum = 0.0;
	}
	cout << maxp << "\n";
	return 0;

}
