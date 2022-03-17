/*

g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill15.cpp `fltk-config --ldflags --use-images` -o 15.out

*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <iostream>
#include <string>

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x);}

int main(){
	try{
		const int win_pos = 100;
		const int win_size = 600;
		const int origo = win_size/2;

		Point t1{win_pos, win_pos};

		Simple_window win{t1, win_size, win_size, "Function Graphs"};

		const int ax_length = 400; //axis's length
		const int ax_scale = 20; //axis's scaling

		Axis ax {Axis::x, Point{origo-(ax_length/2), origo}, ax_length, ax_scale, "x:1 == 20 pixels"};
		ax.set_color(Color::red);
		Axis ay {Axis::y, Point{origo, origo+(ax_length/2)}, ax_length, ax_scale, "y:1 == 20 pixels"};
		ay.set_color(Color::red);

		win.attach(ax);
		win.attach(ay);

		const int fun_min = -10;
		const int fun_max = 11;
		const Point origin{origo, origo};
		const int scale = 20;

		Function func1(one, fun_min, fun_max, origin, scale, fun_min, fun_max);

		Function func2(slope, fun_min, fun_max, origin, scale, fun_min, fun_max);
		Text func2_label(Point{origo+4*scale,origo+4*scale}, "x/2");

		Function func3(square, fun_min, fun_max, origin, scale, fun_min, fun_max);

		Function func4(cos, fun_min, fun_max, origin, scale, fun_min, fun_max);
		func4.set_color(Color::blue);

		Function func5(sloping_cos, fun_min, fun_max, origin, scale, fun_min, fun_max);
		func5.set_color(Color::green);

		win.attach(func1);
		win.attach(func2);
		win.attach(func2_label);
		win.attach(func3);
		win.attach(func4);
		win.attach(func5);

		win.wait_for_button();

	} catch (exception& e) {
		cerr << "Exception: " << e.what() << '\n';
		return 1;
	} catch (...) {
		cerr << "Unknown exception, closing program..." << '\n';
		return 2;
	}
}