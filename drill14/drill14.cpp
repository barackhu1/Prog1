/*	1. Define a class B1 with a virtual function vf() and a non-virtual function f() .
Define both of these functions within class B1 . Implement each function
to output its name (e.g., B1::vf() ). Make the functions public . Make a B1
object and call each function.
	
	2. Derive a class D1 from B1 and override vf() . Make a D1 object and call vf()
and f() for it.
	
	3. Define a reference to B1 (a B1& ) and initialize that to the D1 object you
just defined. Call vf() and f() for that reference.
	
	4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
	
	5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Ex-
plain the result.
	
	6. Define a class D2 derived from D1 and override pvf() in D2 . Make an
object of class D2 and invoke f() , vf() , and pvf() for it.

	7. Define a class B2 with a pure virtual function pvf() . Define a class D21
with a string data member and a member function that overrides pvf() ;
D21::pvf() should output the value of the string . Define a class D22 that
is just like D21 except that its data member is an int . Define a function f()
that takes a B2& argument and calls pvf() for its argument. Call f() with a
D21 and a D22 .*/

#include <iostream>
#include <string>

using namespace std;

//1.feladat

class B1{
public:
	virtual void vf(){cout << "B1::vf()" << endl;}; //kiírja virtuálisan hogy B1::vf()
	void f(){cout << "B1::f()" << endl;};
	/*5.feladat*/ virtual void pvf()=0; //abztrakt függvény
};

//2.feladat

class D1: public B1{
public:
	virtual void vf(){cout << "D1::vf()" << endl;};
	/*4.feladat*/ void f(){cout << "B1::f()" << endl;};
};

//6.feladat

class D2: public D1{
public:
	void pvf(){cout<<"D2::pvf()"<<endl;}; //így már nem lesz absztrakt meg megmondjuk mit csináljon
};

//7.feladat

class B2{
public:
	virtual void pvf()=0; //tisztán virtuális ami jelzi hogy felül van írva, absztarkt
};

class D21 : public B2{
	public:
		string s;
		void pvf(){cout<<s<<endl;}; //felülírja, nem lesz absztrakt
};

class D22 : public B2{
	public:
		int n;
		void pvf(){cout<<n<<endl;}; //felülírja, nem lesz absztrakt
};

void f(B2& b2) //függvény aminek az argumentuma B2 referencia, referencia miatt meg lehet hívni a D21 és D22 osztályt
{
	b2.pvf();
}

int main(){

	//1.feladat

	/*B1 b1;
	b1.vf();
	b1.f();
	cout << endl;

	//2.feladat

	D1 d1;
	d1.vf();
	d1.f();
	cout << endl;

	//3.feladat

	B1& b1ref=d1; //a virtuális void miatt a függvényünk a referencia miatt a B1-ből fog referálni, de a nem virtuális fügvény a D1-ből fog
	b1ref.vf();
	b1ref.f();
	cout << endl;

	//4.feladat

	d1.vf();
	d1.f();
	cout << endl;*/

	//6.feladat

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	cout << endl;

	//7.feladat

	D21 d21;
	d21.s = "d21.s";
	d21.pvf();

	D22 d22;
	d22.n = 22;
	d22.pvf();

	f(d21);
	f(d22);

}