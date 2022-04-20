#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Fruit{

	string name;
	int quantity;
	double unit_price;
	Fruit(const string& n, int q=0, double p = 0.0): name{n}, quantity{q},unit_price{p}{}

};

struct Fruit_cmp_ptr{
	bool operator()(const Fruit* a, const Fruit* b){
		return a->name < b->name;
		//return a->quantitiy < b->quantity;
	}
};

int main()
try{
	vector<Fruit> vf {
		Fruit{ "Plum", 3},
		Fruit{ "Grape", 32},
		Fruit{ "Banana", 11},
		Fruit{ "Orange", 75},
		Fruit{ "Cherry", 47},
		Fruit{ "Plum", 33},
		Fruit{ "Kiwi", 29}
	};
	cout << "Vector values:" << endl;
	for (const auto& f : vf)
	{
		cout << f.name << endl;
	}
		cout << endl;
	set<Fruit*> sf;
	for (const auto& f : vf)
	{
		sf.insert(&f);
	}

	cout << "Set values:";
	for (const auto& f : sf)
	{
		cout << f->name << endl;
	}
	cout << endl;
} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}