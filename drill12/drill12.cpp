/*	1. Get an empty Simple_window with the size 600 by 400 and a label My
window compiled, linked, and run. Note that you have to link the FLTK
library as described in Appendix D; #include Graph.h and Simple_
window.h in your code; and include Graph.cpp and Window.cpp in your
project.
	
	2. Now add the examples from §12.7 one by one, testing between each
added subsection example.
	
	3. Go through and make one minor change (e.g., in color, in location, or in
number of points) to each of the subsection examples.*/

//g++ drill12.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`

#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){

	try{

		Point tl{100,100};
		Simple_window win {tl,600,400,"My window"};
		win.wait_for_button();

		Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
		xa.set_color(Color::dark_magenta);
		xa.label.set_color(Color::dark_blue);
		win.attach(xa);
		win.label("My window");
		win.wait_for_button();

		Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::yellow);
		win.attach(ya);
		win.label("My window");
		win.wait_for_button();

		Function sine {sin,0,100,Point(20,150),1000,50,50};
		win.attach(sine);
		win.label("My window");
		win.wait_for_button();

		sine.set_color(Color::magenta);

		Polygon poly;
		poly.add(Point{350,200});
		poly.add(Point{450,200});
		poly.add(Point{400,100});
		poly.set_color(Color::red);
		win.attach(poly);
		win.label("My windows");
		win.wait_for_button();

		Rectangle r {Point{200,200},100,50};
		win.attach(r);
		win.label("My window");
		win.wait_for_button();

		Closed_polyline poly_rect;
		poly_rect.add(Point{100,50});
		poly_rect.add(Point{200,50});
		poly_rect.add(Point{200,100});
		poly_rect.add(Point{100,100});
		win.attach(poly_rect);
		win.label("My window");
		win.wait_for_button();

		poly_rect.add(Point{50,75});
		win.attach(poly_rect);
		win.label("My window");
		win.wait_for_button();

		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash,4));
		poly_rect.set_style(Line_style(Line_style::dashdotdot,4));
		poly_rect.set_fill_color(Color::dark_green);
		win.set_label("My window");
		win.wait_for_button();

		Text t {Point{100,150},"Szeretem a tejet!"};
		win.attach(t);
		win.label("My window");
		win.wait_for_button();

		t.set_font(Font::symbol);
		t.set_font_size(20);
		win.set_label("My window");
		win.wait_for_button();

		Image ii {Point{100,50},"badge.jpg"};
		win.attach(ii);
		win.set_label("My window");
		win.wait_for_button();

		ii.move(100,300);
		win.set_label("My window");
		win.wait_for_button();

		Circle c {Point{100,200},50};
		Ellipse e {Point{100,200}, 75,25};
		e.set_color(Color::dark_red);
		Mark m {Point{100,200},'x'};
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes {Point{100,20},oss.str()};
		Image cal {Point{100,50},"byalex.jpeg"};
		//cal.set_mask(Point{40,40},200,150);
		win.attach(c);
		win.attach(e);
		win.attach(m);
		win.attach(sizes);
		win.attach(cal);
		win.set_label("My window");
		win.wait_for_button();

	}catch(exception & e){

		cerr<<"exception: " << e.what() << endl;
		return 1;

	}catch(...){

		cerr << "exception\n";
		return 2;

	}

}