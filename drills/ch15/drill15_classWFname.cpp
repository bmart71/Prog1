//#include <iostream>
//#include <string>
#include "GUI/std_lib_facilities.h"

//using namespace std;

struct Person{
public:
	Person(): forename(""),surname(""), age_var(0) {};
	Person(string fn, string sn, int a): forename(fn), surname(sn), age_var(a){
		if (a < 0 || 150 < a) error("Age must be within range of [0:150) \n");
		string fln = forename + surname;
		const string invalid_chars = ";:\"[]*&^%$#@!'";
		for (int i = 0; i < fln.size(); i++)
			for(int j = 0; j < invalid_chars.size(); j++)
				if(fln[i] ==  invalid_chars[j]) error("Unsupported character found");
	};
	string fname() const { return forename; };
	string sname() const { return surname; };
	int age() const { return age_var; };
private:
	string forename;
	string surname;
	int age_var;
};

istream& operator>>(istream& is, Person& p)
{
	string fname, sname;
	int age;
	is >> fname >> sname >> age;
	if (!is) return is;
	p = Person(fname, sname, age);
	return is;
}

ostream& operator<<(ostream& os, const Person& p){
	return os << "Full name: " << p.fname() << " " << p.sname() << '\n'
	<< "Age: " << p.age() << '\n';
}


int main(){
	/*
	Person P;
	P.name_var = "Goofy";
	P.age_var = 63;

	cout << P.name_var << " " << P.age_var << '\n';

	cout << "Please enter a person's name and age (Name Age): ";
	Person p2;
	cin >> p2;
	cout << p2 << endl;*/

	vector<Person> P;

	cout << "Enter names and ages with this format: (Name age), and terminate it with 'end'.\n";

	for(Person p; cin >> p;)
	{
		if (p.fname() == "end") break;
		P.push_back(p);
	}
	for(auto PS : P)
		cout << PS;

	return 0;
}