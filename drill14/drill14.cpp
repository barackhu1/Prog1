#include <iostream>
#include <string>

using namespace std;

class B1{ //absztrakt osztály
	public:
		virtual void vf() {cout <<"B1::vf()"<<endl;} //kiírja virtuálisan hogy B1::vf()
		void f() {cout << "B1::f()"<<endl;} //kiírja hogy B1::f()
		virtual void pvf()=0; //abztrakt függvény
};

class D1 : public B1{ //public mindig kell oda
	public:
	void vf() {cout<<"D1::vf()"<<endl;}
	void f() {cout<<"D1::f()"<<endl;}
};

class D2 : public D1{
	public:
		void pvf(){cout<<"D2::pvf()"<<endl;} //így már nem lesz absztrakt meg megmondjuk mit csináljon
};

class B2 {
	public:
		virtual void pvf()=0; //tisztán virtuális ami jelzi hogy felül van írva, absztarkt
};


class D21 : public B2{
	public:
		string s;
		void pvf(){cout<<s<<endl;} //felülírja, nem lesz absztrakt
};
class D22 : public B2{
	public:
		int n;
		void pvf(){cout<<n<<endl;} //felülírja, nem lesz absztrakt
};

void f(B2& b2) //függvény aminek az argumentuma B2 referencia, referencia miatt meg lehet hívni a D21 és D22 osztályt
{
	b2.pvf();
};


int main(){
	/*B1 b1; //B1 osztály b1 objektummal
	b1.vf(); //a B1 osztályból meghíja a vf() és f() függvényeket b1 objektummal
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f();
	d1.f();
	d1.f();
	d1.f();	
		
	B1& b1ref=d1; //a virtuális void miatt a függvényünk a referencia miatt a B1-ből fog referálni, de a nem virtuális fügvény a D1-ből fog
	b1ref.vf();
	b1ref.f();*/
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();	
	
	D21 d21;
	d21.s="d21.s";
	d21.pvf();
	
	D22 d22;
	d22.n=22;
	d22.pvf();

	f(d21);
	f(d22);

}