/*	1. Define a struct Item { string name; int iid; double value;}; , make
a vector<Item> , vi , and fill it with ten items from a file.
	
	2. Sort vi by name.
	
	3. Sort vi by iid .
	
	4. Sort vi by value; print it in order of decreasing value (i.e., largest value
first).
	
	5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95) .
	
	6. Remove (erase) two Item s identified by name from vi .
	
	7. Remove (erase) two Item s identified by iid from vi .
	
	8. Repeat the exercise with a list<Item> rather than a vector<Item>.*/


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>

using namespace std;

//1.feladat

struct Item {
    string name;
    int id;
    double value;
    Item() : name("nothing"), id(0), value(0) {}
    Item(const string& n, int i = 0, double v = 0.0) : name{ n }, id{ i }, value{ v }{}
};

istream& operator>>(istream& is, Item& it) {

    string n;
    int id;
    double v;
    is >> n >> id >> v;
    Item vii{ n, id, v };
    it = vii;
    return is;

}

template<typename C>
void print(const C& c, char sep = ' ') {
    for (const auto& i : c)
    {
        cout << i.name << sep << i.id << sep << i.value << endl;
    }
    cout << endl;
}

//2.feladat

struct sort_by_name {
    bool operator()(const Item& a, const Item& b) const {
        return a.name < b.name;
    }
};

//3.feladat

struct sort_by_id {
    bool operator()(const Item& a, const Item& b) const {
        return a.id < b.id;
    }
};

//4.feladat

struct sort_by_value_decreasing {
    bool operator()(const Item& a, const Item& b) const {
        return a.value > b.value;
    }
};

//6.feladat

class find_name{
private:
    string name;
public:
    find_name(const string& nn){name=nn;} //: name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

//7.feladat

class find_iid{
private:
    int iid;
public:
    find_iid(int id){iid=id;} //: iid{id} { }
    bool operator()(const Item& x) const { return x.id == iid; }
};

int main()
try {

	//1.feladat

    const string iname{ "file.txt" };
    ifstream ifs{ iname };
    if (!ifs) throw runtime_error("Could not read file: " + iname);

    vector<Item> vi;
    for (Item d; ifs >> d;) {
        vi.push_back(d);
    }
    cout << "Items:" << endl;
    print(vi);

    //8.feladat

    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

    //2.feladat

    sort(vi.begin(), vi.end(), sort_by_name());
    cout << "Items sorted by name:" << endl;
    print(vi);

    //3.feladat

    sort(vi.begin(), vi.end(), sort_by_id());
    cout << "Items sorted by id:" << endl;
    print(vi);

    //4.feladat

    sort(vi.begin(), vi.end(), sort_by_value_decreasing());
    cout << "Items sorted by value in descending order:" << endl;
    print(vi);

    //5.feladat

    vi.push_back(Item{ "horse shoe", 99, 12.34 });
    vi.push_back(Item{ "Canon S400", 9988, 499.95 });
    cout << "Items:" << endl;
    print(vi);

    //6.feladat

    vi.erase(find_if(vi.begin(), vi.end(), find_iid(44)));
    vi.erase(find_if(vi.begin(), vi.end(), find_iid(37)));
    cout << "Items deleted by name:" << endl;
    print(vi);

    //7.feladat
    
    vi.erase(find_if(vi.begin(), vi.end(), find_name("computer")));
    vi.erase(find_if(vi.begin(), vi.end(), find_name("tv")));
    cout << "Items deleted by id:" << endl;
    print(vi);

    //8.feladat

    cout << "List items:" << endl;
    print(li);

    li.sort(sort_by_name());
    cout << "List items sorted by name:" << endl;
    print(vi);

    li.sort(sort_by_id());
    cout << "List items sorted by id:" << endl;
    print(vi);

    li.sort(sort_by_value_decreasing());
    cout << "List items sorted by value descending:" << endl;
    print(vi);

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

	li.erase(find_if(li.begin(), li.end(), find_iid(44)));
    li.erase(find_if(li.begin(), li.end(), find_iid(37)));

    li.erase(find_if(li.begin(), li.end(), find_name("computer")));
    li.erase(find_if(li.begin(), li.end(), find_name("tv")));

}
catch (exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Unknown exception!" << '\n';
    return 2;
}