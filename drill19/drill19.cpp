/*	1. Define template<typename T> struct S { T val; }; .
	
	2. Add a constructor, so that you can initialize with a T .
	
	3. Define variables of types S<int> , S<char> , S<double> , S<string> , and
S<vector<int>> ; initialize them with values of your choice.
	
	4. Read those values and print them.

	5. Add a function template get() that returns a reference to val .

	6. Put the definition of get() outside the class.

	7. Make val private.

	8. Do 4 again using get() .

	9. Add a set() function template so that you can change val .

	10. Replace set() with an S<T>::operator=(const T&) . Hint: Much simpler
than §19.2.5.

	11. Provide const and non- const versions of get() .

	12. Define a function template<typename T> read_val(T& v) that reads from
cin into v .
	
	13. Use read_val() to read into each of the variables from 3 except the
S<vector<int>> variable.

	14. Bonus: Define input and output operators ( >> and << ) for vector<T> s.
For both input and output use a { val, val, val } format. That will allow
read_val() to also handle the S<vector<int>> variable.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//1.feladat

template<typename T>
struct S {
	/*2.feladat*/S (T vv = 0) : val{vv}{};
	/*5.feladat*/T& get();
	/*9.feladat*/void set(T new_t) {val = new_t;}
	/*10.feladat*/void operator=(const T& s){val = s;};
	/*11.feladat*/const T& get() const;

	//7.feladat
private:
	T val;
};

//5. és 6.feladat

template<typename T>
T& S<T>::get(){
	return val;
}

//11.feladat

template<typename T>
const T& S<T>::get() const{
	return val;
}

/*template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}*/

//12.feladat

template<typename T>
void read_val(T& v){
	cin >> v;
}

//14.feladat

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i < v.size()-1)
		{
			os << ", ";
		}
	}
	os << "}";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main(){
	
	//3.feladat

	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss{"Hello"};
	S<vector<int>> svi {vector<int>{1,1,2,3,5,8}};

	//4. és 8.feladat

	cout << "S<int> : " << s.get() << endl;
	cout << "S<int> : " << si.get() << endl;
	cout << "S<char> : " << sc.get() << endl;
	cout << "S<double> : " << sd.get() << endl;
	cout << "S<string> : " << ss.get() << endl;
	cout << "S<vector<int>> : " << svi.get() << endl;

	/* vector régi kiiratása
	cout << "S<vector<int>> : ";

	for (auto& a: svi.get())
	{
		cout << a << ' ';
	}*/

	//8.feladat

	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;

	//10.feladat

	sd = 42.1;
	cout << "S<double> : " << sd.get() << endl;

	//13.feladat

	int ii;
	read_val(ii);
	S<int> si2 {ii};

	double dd;
	read_val(dd);
	S<double> sd2 {dd};

	string ss2;
	read_val(ss2);
	S<string> str {ss2};

	cout << "S<int> : " << si2.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	cout << "S<string> : " << str.get() << endl;

	//14.feladat

	cout << "Add a vector in this format {val, val, val}: ";
	vector<int> vint;
	read_val(vint);
	S<vector<int>> svi2 {svi2};

	cout << "S<vector<int>> : " << svi.get() << endl;

}