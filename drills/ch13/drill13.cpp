/*

to run:

g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill13.cpp `fltk-config --ldflags --use-images` -o a13.out


*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try {
		Point W1 {300, 50};
		Simple_window win{W1, 800, 800, "My Window"};
		win.wait_for_button();
		int x_size = 800;
		int y_size = 800;
		Lines grid;

		for(int i=0; i < 800; i+=100){
			grid.add(Point {i, 0}, Point{i, y_size});
			grid.add(Point {0, i}, Point{x_size, i});
		}
		win.attach(grid);
		win.wait_for_button();
		
		vector<Rectangle*> rects;
		int rectCount = min(1000, 800) / 100;
		for(int i = 0; i < rectCount; i++){
			rects.push_back( new Rectangle( Point{i*100, i*100}, 100, 100));
			rects[i]->set_fill_color(Color::red);
			win.attach(*rects[i]);
		}
		
		win.wait_for_button();

		Image bdg{Point{0,0}, "badge.jpg"};
		bdg.set_mask(Point{100,100}, 200, 200);
		win.attach(bdg);
		win.wait_for_button();

		Image bag{Point{0,200}, "badge.jpg"};
		bag.set_mask(Point{150,150}, 100, 100);
		win.attach(bag);

		for(int i = 0; i < 4; i++){
			bag.move(i*100,0);
			win.wait_for_button();
		}
	}
	catch (exception &e){
		cerr << "exception: " << e.what() << '\n';
		return 1;
	} catch (...) {
		cerr << "an unknown error occured!\n";
		return 2;
	}
}
