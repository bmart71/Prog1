#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <exception>

template<typename C>
void print(const C& c){
	for (auto& i : c){
		std::cout << i << ' ';		
	}
	std::cout << std::endl;
}

template<typename C>
void inc(C& c, int n){
	for(auto& i : c)
		i+=n;
}

template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
//	from [f2,e1) to [f2, f2+(e1-f1))
	for (Iter1 p = f1; p != e1; p++){
		*f2++ = *p; //==  *f2 = *p then *f2++
//		f2++;
	}
	return f2;
}

//using namespace std;

int main() {
	try{
		constexpr int size = 10;

		int arr[size] = {0,1,2,3,4,5,6,7,8,9};

		std::array<int, size> ai;
		std::copy(arr, arr+size, ai.begin());

		std::vector<int> vi(size);
		std::copy(arr, arr+size, vi.begin());

		std::list<int> li(size);
		std::copy(arr, arr+size, li.begin());

		std::array<int, size> ai2 = ai;
		std::vector<int> vi2 = vi;
		std::list<int> li2 = li;

		print(ai2);
		print(vi2);
		print(li2);
		
		inc(ai2, 1);
		inc(vi2, 2);
		inc(li2, 3);
		
		print(ai2);
		print(vi2);
		print(li2);
		
		orai_copy(ai2.begin(), ai2.end(), vi2.begin());
		orai_copy(li2.begin(), li2.end(), ai2.begin());
		
		print(ai2);
		print(vi2);
		print(li2);
		
		std::vector<int>::iterator vit;
		vit = std::find(vi2.begin(), vi2.end(), 3);
		if ( vit != vi2.end() ){
			std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
		} else {
			std::cout << "Not found" << '\n';
		}

		vit = std::find(vi2.begin(), vi2.end(), 27);
		if ( vit != vi2.end() ){
			std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
		} else {
			std::cout << "Not found" << '\n';
		}		
		
				
	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr << "Unknown exception" << std::endl;
		return 2;
	}
}
