/*  1. Make an 800-by-1000 Simple_window .

    2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that
each square is 100 by 100).

    3. Make the eight squares on the diagonal starting from the top left corner
red (use Rectangle ).

    4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
on the grid (each image covering four squares). If you can’t find an image
that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
a larger image. Don’t obscure the red squares.

    5. Add a 100-by-100 image. Have it move around from square to square
when you click the “Next” button. Just put wait_for_button() in a loop
with some code that picks a new square for your image.*/

//g++ drill13.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){

    try{

        srand(time(0));
        int x = 8;
        int y = 8;

        //1.feladat

        Simple_window win{Point{0,200}, 800, 1000, "My window"};
        win.wait_for_button();

        //2.feladat

        Lines grid;
        for (int i = 0; i <= (x*100);i+=100)
        {
            grid.add(Point(0,i), Point(x*100, i));
        }
        for (int i = 0; i <= (y*100); i+=100)
        {
            grid.add(Point(i,0), Point(i, y*100));
        }
        win.attach(grid);
        win.wait_for_button();

        //3.feladat

        Vector_ref<Rectangle> rec;
        for (int i = 0; i < 8; ++i)
        {
            rec.push_back(new Rectangle{Point{i*100,i*100}, Point{(i+1)*100,(i+1)*100}});
            rec[i].set_fill_color(Color::red);
            rec[i].set_color(Color::invisible);
            win.attach(rec[i]);
        }
        win.wait_for_button();

        //4.feladat

        Image ii1 (Point{0,200},"simpson.jpg");
        win.attach(ii1);
        Image ii2 (Point{600,200},"simpson.jpg");
        win.attach(ii2);
        Image ii3 (Point{100,600},"simpson.jpg");
        win.attach(ii3);
        win.wait_for_button();

        //5.feladat

        int r1 = (rand()%x)*100, r2 = (rand()%y)*100;
        Image ii4 (Point{r1, r2}, "bruh.gif");
        win.attach(ii4);
        win.wait_for_button();
        while(true){
            ii4.move(-r1, -r2);
            r1 = (rand()%x)*100, r2 = (rand()%y)*100;
            ii4.move(r1, r2);
            win.attach(ii4);
            win.wait_for_button();
        }

    }catch(exception & e){

        cerr<<"exception: " << e.what() << endl;
        return 1;

    }catch(...){

        cerr << "exception\n";
        return 2;

    }

}