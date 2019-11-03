#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <iomanip>
using namespace std;

template <typename T1, typename T2> typename T1::value_type quant(const T1& x, T2 q)
{
	const auto n = x.size();
	const auto id = (n - 1) * q;
	const auto lo = floor(id);
	const auto hi = ceil(id);
	const auto qs = x[lo];
	const auto h = (id - lo);

	return (1.0 - h) * qs + h * x[hi];
}

int main(int argc, char *argv[])
{
	ifstream F(argv[1]);
	vector<double> x;
	string fl;
	while (F >> fl) {
		double temp = atof(fl.c_str());
		x.push_back(temp);
	}
	sort(x.begin(), x.end());
	double av = accumulate(x.begin(), x.end(), 0.0) / x.size();
	cout << fixed << setprecision(2) << quant(x, 0.90) << "\n";
	cout << fixed << setprecision(2) << quant(x, 0.50) << "\n";
	cout << fixed << setprecision(2) << x.back() << "\n";
	cout << fixed << setprecision(2) << x.front() << "\n";
	cout << fixed << setprecision(2) << av << "\n";
	return 0;
}


