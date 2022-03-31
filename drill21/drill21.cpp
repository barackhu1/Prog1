#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

using namespace std;

template<typename K, typename V>
void print(const map<K,V>& m){
	for (pair<K,V> i:m)
	{
		cout << i.first << '\t' << i.second << endl;
	}
}

void read_map(map<string,int>& m){
	string s;
	int i = 0;
	while(m.size() < 10){
		cin >>s>>i;
		m[s] = i;
		//m.insert(make_pair(s,i));
	}
}

template<typename K, typename V>
int sum(map<K,V>& m){
	int sum = 0;
	for (pair<K,V> i:m)
	{
		sum += i.second;
	}
	return sum;
}

int main()
try{

	map<string, int> msi;

	msi["a"] = 2;
	msi["b"] = 3;
	msi["abc"] = 4;
	msi["cd"] = 5;
	msi["qwert"] = 2;
	msi["gz"] = 32;
	msi["tar"] = 12;
	msi["x"] = 8;
	msi["xp"] = 7;
	msi["asd"] = 21;
	print(msi);

	msi.erase("a");
	cout << endl << "Egy elem törlése után: " << endl;
	print(msi);

	msi.erase(msi.begin(), msi.end());
	cout << endl << "Teljes törlés után: " << endl;
	print(msi);

	cout << "Adj meg 10 kulcs érték párt" << endl;
	read_map(msi);
	print(msi);

	cout << "A számok összege: " << endl;
	cout << sum(msi) << endl;

	map<int,string> mis;
	for (pair<string, int> a : msi)
	{
		mis[a.second] = a.first;
	}

	cout << "mis map: " << endl;
	print(mis);

} catch(exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception" << '\n';
	return 2;
}