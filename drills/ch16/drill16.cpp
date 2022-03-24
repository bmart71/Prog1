#include "GUI/Lines_window.h"
#include "GUI/Graph.h"

int main(){
	try{
		Lines_window win {Point{150,150}, 600, 400, "Lines"};
		return gui_main();
	} catch (exception& e){
		cerr << "Exception: " << e.what() << '\n';
	} catch (...) {
		cerr << "Unknown exception" << '\n';
	}
}