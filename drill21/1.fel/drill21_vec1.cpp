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

struct Item{
	string name;
	int id;
	double value;
};

istream& operator>>(istream& is, Item& it){

	string n;
	int id;
	double v;
	is >> n >> id >> v;
	Item vii{n, id, v};
	it = vii;
	return is;

}

template<typename C>
void print(const C& c, char sep = ' '){
	cout << "Items: " << endl;

	for (const auto& f : c)
	{
		cout << f.name << sep 
		<< f.id << sep 
		<< f.value << endl;
	}
	cout << endl;
}

int main()
try{
	const string iname {"file.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: "+iname);

	vector<Item> vi;
    for (Item d; ifs >> d;){
        vi.push_back(d);
    }
    print(vi);

    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    print(vi);

    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.id < b.id; });
    print(vi);

    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.value > b.value; });
    print(vi);

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});
    print(vi);

    

} catch(exception& e) {
	cerr << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}