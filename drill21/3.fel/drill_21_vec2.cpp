#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

template<typename C>
void print(const C& c, char sep = '\n'){
	cout << "Container elements: " << endl;

	for (const auto elem: c)
	{
		cout << elem << sep;
	}
	cout << endl;
}

template<typename C>
double sum(const C& c){
	double s;
	for(const auto elem: c){
		s += elem;
	}
	return s;
}

int main()
try{
	const string iname {"file.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: "+iname);

	vector<double> vd;
	for (double d; ifs >> d;)
	{
		vd.push_back(d);
	}

	print(vd);

	vector<int> vi(vd.size());
	/*for(auto i: vd){
		vi.push_back(i);
	}*/
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);

	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << '\t' << vi[i] << endl;
	}
	cout << endl;

	cout << "Sum of vd: " << sum(vd);
	cout << endl;

	cout << "Difference between the sum of vd and vi: " << sum(vd) - sum(vi);
	cout << endl;

	reverse(vd.begin(), vd.end());
	print(vd);

	double vd_mean = sum(vd)/vd.size();
	cout << "Mean value of vd is: " << vd_mean << endl;

	vector<double> vd2;
	for(auto i: vd){
		if (i < vd_mean)
		{
			vd2.push_back(i);
		}
	}
	print(vd2);

	sort(vd.begin(),vd.end());
	print(vd);

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}