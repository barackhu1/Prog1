#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x) + cos(x); }

int main(){
	try{

		Point tl{600,300};
		Simple_window win {tl,600,600,"Function graphs."};

		Axis xa {Axis::x, Point{100,300}, 400, 20, "1 = = 20 pixels"};
		xa.set_color(Color::red);
		win.attach(xa);
		Axis ya {Axis::y, Point{300,500}, 400, 20, "1 = = 20 pixels"};
		ya.set_color(Color::red);
		win.attach(ya);
		win.wait_for_button();

		const int r_min = -10;
		const int r_max = 11;
		const int points = 400;
		const int x_scale = 20;
    	const int y_scale = 20;
    	Point origo = Point{300,300};
    	Function f1 {one, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f1);
    	win.wait_for_button();

    	Function f2 {slope, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f2);

    	Text tf2 {Point{100,380},"x/2"};
    	win.attach(tf2);
    	win.wait_for_button();

    	Function f3 {square, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f3);
    	win.wait_for_button();

    	Function cosine {cos,r_min, r_max, origo, points, x_scale, y_scale};
    	cosine.set_color(Color::blue);
    	win.attach(cosine);
    	win.wait_for_button();

    	Function f4 {sloping_cos, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f4);
    	win.wait_for_button();

	}catch(exception & e){

		cerr<<"exception: " << e.what() << endl;
		return 1;

	}catch(...){

		cerr << "exception\n";
		return 2;

	}

}