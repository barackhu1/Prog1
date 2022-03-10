#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Person{
	public:
		Person(){};
		Person(string f, string l, int a) : f{f}, l{l}, a{a}{
			if (a < 0 || a >=150)
			{
				throw runtime_error ("Invalid age!");
			}
			string n = f + l;
			for (int i = 0; i < n.length(); ++i)
			{
				if (n[i] == ';' || n[i] == ':' || n[i] == '"' || n[i] == '[' ||  n[i] == 96 || n[i] == ']' || n[i] == '*' || n[i] == '&' || n[i] =='^' || n[i] == '%' || n[i] == '$' || n[i] == '#' || n[i] == '@' || n[i] == '!')
				{
					throw runtime_error ("Invalid name!");
				}
			}
		};
		string first() const{return f;}
		string last() const{return l;}
		int age() const{return a;}
	private:
		//string n;
		string f;
		string l;
		int a;
};

ostream& operator<< (ostream& os, const Person& p){return os << p.first() << " " << p.last() << " " << p.age();}
istream& operator>> (istream& is, Person& p){
	string f;
	string l;
	int a;
	is >> f >> l >> a;
	p=Person(f, l, a);
	return is;
}

int main(){

	Person p1;
	//p1.n = "Goofy";
	//p1.a = 63;
	p1 = Person("Goofy", "Goofy", 63);
	cout << p1.first() << " " << p1.last() << " " << p1.age() << endl;

	Person p2;
	Person p3;
	cin >> p2 >> p3;
	cout << p2 << " " << p3 << endl;

	vector<Person> vec;

	for (Person p; cin >> p;)
	{
		if (p.first() == "end") break;
		vec.push_back(p);
	}

	for (Person p: vec)
	{
		cout << p << endl;
	}

}