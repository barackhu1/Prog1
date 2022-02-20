#include "../GUI/Graph.h"
#include "../GUI/Simple_window.h"

#include <iostream>
#include <string>

using namespace Graph_lib;

int main(){

    try{

        Simple_window win{Point{0,200}, 800, 1000, "My window"};
        win.wait_for_button();

        Lines grid;
        int x = 800;
        int y = 800;
        for (int i = 0; i <= x; i+=100)
        {
            grid.add(Point(0,i), Point(x, i));
        }
        for (int i = 0; i <= y; i+=100)
        {
            grid.add(Point(i,0), Point(i, y));
        }
        win.attach(grid);
        win.wait_for_button();

        Vector_ref<Rectangle> rec;
        for (int i = 0; i < 8; ++i)
        {
            rec.push_back(new Rectangle{Point{i*100,i*100}, Point{(i+1)*100,(i+1)*100}});
            rec[i].set_fill_color(Color::red);
            win.attach(rec[i]);
        }
        win.wait_for_button();

        Image ii1 (Point{0,200},"simpson.jpg");
        win.attach(ii1);
        Image ii2 (Point{600,200},"simpson.jpg");
        win.attach(ii2);
        Image ii3 (Point{100,600},"simpson.jpg");
        win.attach(ii3);
        win.wait_for_button();

        srand(time(0));
        int nx = 8;
        int ny = 8;
        int r1 = (rand()%nx)*100, r2 = (rand()%ny)*100;
        Image ii4 (Point{r1, r2}, "bruh.gif");
        win.attach(ii4);
        win.wait_for_button();
        while(true){
            ii4.move(-r1, -r2);
            r1 = (rand()%nx)*100, r2 = (rand()%ny)*100;
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