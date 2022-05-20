#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S {
	S(T vv = 0) : val{vv}{};
	const T& get() const;
	// T& set(T v);
	void set(T new_t) { val = new_t; }
	void read_val(T& v);
	void operator=(const T& s);
private:
	T val;
};

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}

template<typename T>
std::ostream& operator<<(ostream& os, const vector<T>& v){
	os << "{ ";
	for (int i = 0; i < v.size(); ++i){
		os << v[i] << (i < v.size() - 1 ? ", " : " ");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	// {1, 1, 2, 3}
	char ch = 0;
	is >> ch;
	if (ch != '{') {
		is.unget();
		return is;
	}
	for(T val; is >> val;) {
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

int main(){
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {vector<int>{1,1,2,3,5,8}};

	cout << "S<int> : " << s.get() << endl
	<< "S<int> : " << si.get() << endl
	<< "S<char> : " << sc.get() << endl
	<< "S<double> : " << sd.get() << endl
	<< "S<string> : " << ss.get() << endl;
	// << "S<vector<int>> : " << svi.val << std::endl;

	cout << "SS<vector<int>> : ";
	for (auto& a : svi.get())
	cout << a << ' ';
	cout << "\n\n";

	s.set(5);
	cout << "S : " << s.get() << "\n\n";

	sd = 42.1;
	cout << "S : " << sd.get() << "\n\n";

	int ii;
	cout << "Please enter an integer type: ";
	read_val(ii);
	S<int> si2 {ii};

	double dd;
	cout << "Please enter a double type: ";
	read_val(dd);
	S<double> sd2 {dd};

	string str;
	cout << "Please enter a string type: ";
	read_val(str);
	S<string> ss2 {str};

	cout << "S<int> : " << si2.get() << "\n";
	cout << "S<double> : " << sd2.get() << "\n";
	cout << "S<string> : " << ss2.get() << "\n\n";

	cout << "S<vector<int>> svi2: ( format: \"{val, val2, val3}\" ) ";
	vector<int> vec;
	read_val(vec);
	S<vector<int>> svi2 {vec};

	cout << "S<vector<int>> svi2: " << svi2.get() << endl;
	return 0;
}
