#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <numeric>

using namespace std;

template<typename K, typename V>
void print(const map<K,V>& m){
	for (auto& i : m){
		cout << i.first << '\t' << i.second << endl;
	}
}

//5.:
void read_map(map<string, int>& m){
	string s;
	int i = 0;
	while (m.size() < 10) {
		cin >> s >> i;
		m.insert(make_pair(s, i));
	}
}

template<typename K, typename V>
int map_sum(const map<K,V>& m){
	int sum_m = 0;
	for(pair<K,V> i : m)
		sum_m += i.second;
	return sum_m;
}

int main(){
	try {
//1.:
		map<string, int> msi;
//2,6.:
		msi["a"] = 1;
		msi["b"] = 3;
		msi["ab"] = 7;
		msi["efgh"] = 98;
		msi["xy"] = 76;
		msi["qw"] = 61;
		msi["efh"] = 60;
		msi["xc"] = 23;
		msi["qwertz"] = 11;
		msi["ax"] = 1;
//3,7.:		
		cout << "msi map:" << endl;
		print(msi);
//4.:		
		msi.erase("a");
		cout << "msi map: (removed msi[\"a\"])" << endl;
		print(msi);
		
		msi.erase(msi.begin(), msi.end());
		cout << "msi map: (full erase)" << endl;
		print(msi);

		cout << "enter 10 string, int pairs: " << endl;
		read_map(msi);
		cout << "msi map: (after read_map())" << endl;
		print(msi);		
//8.:			
		int m_sum = map_sum(msi);
		cout << "msi map_sum = " << m_sum << endl;
//9.:		
		map<int, string> mis;
//10.:
		for(pair<string, int> i : msi)
			mis[i.second] = i.first;
//11.:
		cout << "mis map:" << endl;
		print(mis);		

		return 0;
	} catch (exception& e) {
		cerr << e.what() << endl;
		return 1;
	} catch (...) {
		cerr << "Unknown exception occured\n";
		return 2;
	}
}
