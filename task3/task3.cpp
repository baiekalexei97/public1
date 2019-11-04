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
	char* buff = new char[15];
	for (int i = 1; i <= 5; i++) {
		strcpy(c, argv[1]);
		sprintf(buff, "\\Cash%d.txt", i);
		strcat(c, buff);
		ifstream Cash(c);
		while (Cash >> s) {
			v[i-1].push_back(s);
		}
		Cash.close();
	}
	long double max = 0.0;
	int maxp = 0;
	long double sum = 0.0;
	for (int i = 0; i < 16; i++) {
		sum = v[0][i]; 
		sum += v[1][i];
		sum += v[2][i];
		sum += v[3][i];
		sum += v[4][i];
		if (sum > max) {
			max = sum;
			maxp = i+1;
		}
		sum = 0.0;
	}
	cout << maxp << "\n";
	return 0;
}
