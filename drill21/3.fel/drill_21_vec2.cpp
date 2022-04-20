/*	1. Read some floating-point values (at least 16 values) from a file into a
vector<double> called vd .

	2. Output vd to cout .

	3. Make a vector vi of type vector<int> with the same number of elements
as vd ; copy the elements from vd into vi .
	
	4. Output the pairs of ( vd[i] , vi[i] ) to cout , one pair per line.

	5. Output the sum of the elements of vd .

	6. Output the difference between the sum of the elements of vd and the sum
of the elements of vi .

	7. There is a standard library algorithm called reverse that takes a sequence
(pair of iterators) as arguments; reverse vd , and output vd to cout .

	8. Compute the mean value of the elements in vd ; output it.
	
	9. Make a new vector<double> called vd2 and copy all elements of vd with
values lower than (less than) the mean into vd2 .

	10. Sort vd ; output it again.*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <string>
#include <algorithm>
#include <functional>	

using namespace std;

//2.feladat

template<typename C>
void print(const C& c, char sep = '\n'){
	cout << "Container elements: " << endl;

	for (const auto elem: c)
	{
		cout << elem << sep;
	}
	cout << endl;
}

//5.feladat

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

	//1. feladat

	const string iname {"file.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: "+iname);

	vector<double> vd;
	for (double d; ifs >> d;)
	{
		vd.push_back(d);
	}

	//2.feladat

	print(vd);

	//3.feladat

	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());

	//4.feladat

	for (int i = 0; i < vd.size(); ++i)
	{
		cout << vd[i] << '\t' << vi[i] << endl;
	}
	cout << endl;

	//5.feladat

	cout << "Sum of vd: " << sum(vd);
	cout << endl;

	//6.feladat

	cout << "Difference between the sum of vd and vi: " << sum(vd) - sum(vi);
	cout << endl;

	//7.feladat

	reverse(vd.begin(), vd.end());
	print(vd);

	//8.feladat

	double vd_mean = sum(vd)/vd.size();
	cout << "Mean value of vd is: " << vd_mean << endl;

	//9.feladat

	vector<double> vd2;
	for(auto i: vd){
		if (i < vd_mean)
		{
			vd2.push_back(i);
		}
	}
	print(vd2);

	//10.feladat

	sort(vd.begin(),vd.end());
	print(vd);

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}