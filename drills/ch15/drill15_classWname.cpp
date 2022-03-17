//#include <iostream>
//#include <string>
#include "GUI/std_lib_facilities.h"

//using namespace std;

struct Person{
public:
	Person(): name_var(""), age_var(0) {};
	Person(string n, int a): name_var(n), age_var(a){
		if (a < 0 || 150 < a) error("Age must be within range of [0:150) \n");
		const string invalid_chars = ";:\"[]*&^%$#@!'";
		for (int i = 0; i < n.size(); i++)
			for(int j = 0; j < invalid_chars.size(); j++)
				if(n[i] ==  invalid_chars[j]) error("Unsupported character found");
	};
	string name() const { return name_var; };
	int age() const { return age_var; };
private:
	string name_var;
	int age_var;
};

istream& operator>>(istream& is, Person& p)
{
	string name;
	int age;
	is >> name >> age;
	if (!is) return is;
	p = Person(name, age);
	return is;
}

ostream& operator<<(ostream& os, const Person& p){
	return os << "Name: " << p.name() << '\n'
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
		if (p.name() == "end") break;
		P.push_back(p);
	}
	for(auto PS : P)
		cout << PS;

	return 0;
}