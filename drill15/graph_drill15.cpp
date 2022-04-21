/*	I. Function graphing drill:
		
		1. Make an empty 600-by-600 Window labeled “Function graphs.”
		
		2. Note that you’ll need to make a project with the properties specified in the
“installation of FLTK” note from the course website.
		
		3. You’ll need to move Graph.cpp and Window.cpp into your project.
		
		4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
and with a notch every 20 pixels. The axes should cross at (300,300).
	
		5. Make both axes red.

	II. In the following, use a separate Shape for each function to be graphed:
		
		1. Graph the function double one(double x) { return 1; } in the range [–10,11]
with (0,0) at (300,300) using 400 points and no scaling (in the window).
		
		2. Change it to use x scale 20 and y scale 20.
		
		3. From now on use that range, scale, etc. for all graphs.
		
		4. Add double slope(double x) { return x/2; } to the window.
		
		5. Label the slope with a Text "x/2" at a point just above its bottom left end
point.
		
		6.Add double square(double x) { return x*x; } to the window.
		
		7.Add a cosine to the window (don’t write a new function).
		
		8.Make the cosine blue.
		
		9.Write a function sloping_cos() that adds a cosine to slope() (as defined
above) and add it to the window.*/

//g++ drill15.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`

#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

/*II. 1.feladat*/ double one(double x) { return 1; }
/*II. 4.feladat*/ double slope(double x) { return x/2; }
/*II. 6.feladat*/ double square(double x) { return x*x; }
/*II. 9.feladat*/ double sloping_cos(double x) { return slope(x) + cos(x); }

int main(){
	try{

		//I. 1. feladat

		Point tl{600,300};
		Simple_window win {tl,600,600,"Function graphs."};

		//I. 4.feladat

		Axis xa {Axis::x, Point{100,300}, 400, 20, "1 = = 20 pixels"};
		win.attach(xa);
		Axis ya {Axis::y, Point{300,500}, 400, 20, "1 = = 20 pixels"};
		win.attach(ya);

		//I. 5.feladat

		ya.set_color(Color::red);
		xa.set_color(Color::red);
		win.wait_for_button();

		//II.

		const int r_min = -10;
		const int r_max = 11;
		const int points = 400;
		/*II. 2.feladat*/ const int x_scale = 20;
    	/*II. 2.feladat*/ const int y_scale = 20;
		Point origo = Point{300,300};
    	
		//II. 1.feladat

    	Function f1 {one, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f1);
    	win.wait_for_button();

    	//II. 4.feladat

    	Function f2 {slope, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f2);

    	//II. 5.feladaat

    	Text tf2 {Point{100,380},"x/2"};
    	win.attach(tf2);
    	win.wait_for_button();

    	//II. 6.feladaat

    	Function f3 {square, r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(f3);
    	win.wait_for_button();

    	//II. 7.feladat

    	Function cosine {cos,r_min, r_max, origo, points, x_scale, y_scale};
    	win.attach(cosine);

    	//II. 8.feladat

    	cosine.set_color(Color::blue);
    	win.wait_for_button();

    	//II. 9.feladat

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