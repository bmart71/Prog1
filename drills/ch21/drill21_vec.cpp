#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>

using namespace std;

//1.:
struct Fruit{
    string name;
    int quantity;
    double unit_price;

    Fruit (const string& n, int q = 0, double p = 0.0) : name{n}, quantity{q}, unit_price{p}{}
};

struct Fruit_ptr_cmp{
    bool operator()(const Fruit* a, const Fruit* b){
        return a->name < b->name;
    }
};

istream& operator>>(istream& is, Fruit f){
    string n;
    int q;
    double p;
    is >> n >> q >> p;
    Fruit outFr{n,q,p};
    f = outFr;
    return is;
}

int main() {
    try {
        vector<Fruit> vf {
            Fruit{"Plum", 3},
            Fruit{"Grape", 13},
            Fruit{"Banana", 73},
            Fruit{"Apple", 55},
            Fruit{"Orange", 62},
            Fruit{"Cherry", 21},
            Fruit{"Plum", 43},
            Fruit{"Kiwi", 99},
        };

        cout<< "Vector values: " << endl;
        for(auto& i : vf){
            cout << i.name << endl;
        }

        cout << endl;

        set<Fruit*, Fruit_ptr_cmp> sf;
        for (auto& f : vf){
            sf.insert(&f);
        }

        cout<< "Set values: " << endl;
        for(auto& i : sf){
            cout << i->name << endl;
        }
        cout << endl;
//5.:
        Fruit horse("horse shoe",99,12.34);
        Fruit canon("Canon S400",9988,499.95);

        vf.insert(vf.begin(), horse);
        vf.insert(vf.begin(), canon);

        cout<< "Vector values (added two items): " << endl;
        for(auto& i : vf){
            cout << i.name << endl;
        }        
//6.:
        string name="horse shoe";
        vf.erase(std::find_if(vf.begin(),vf.end(),[name](const Fruit& a){return a.name == name;}));

        cout<< "Vector values (removed horse): " << endl;
        for(auto& i : vf){
            cout << i.name << endl;
        }
//7.:
        int id = 99;
        vf.erase(std::find_if(vf.begin(),vf.end(),[id](const Fruit& a){return a.quantity == id;}));

        cout<< "Vector values (removed 99): " << endl;
        for(auto& i : vf){
            cout << i.name << endl;
        }
//8.:

        list<Fruit> li{
            Fruit{"Plum", 3},
            Fruit{"Grape", 13},
            Fruit{"Banana", 73},
            Fruit{"Apple", 55},
            Fruit{"Orange", 62},
            Fruit{"Cherry", 21},
            Fruit{"Plum", 43},
            Fruit{"Kiwi", 99},
        };

        cout<< "list values: " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }


        string a2,b2;
        li.sort([](const Fruit& a2, const Fruit& b2){return a2.name < b2.name;});
        cout<< "list values(sort by name): " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }

        li.sort([](const Fruit& a2, const Fruit& b2){return a2.quantity < b2.quantity;});
        cout<< "list values(sort by quantity): " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }

        li.insert(li.begin(), horse);
        li.insert(li.begin(), canon);
        cout<< "list values(two items added): " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }

        li.erase(find_if(li.begin(), li.end(), [name](const Fruit& a){return a.name == name;}));
        cout<< "list values(horse removed): " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }        

        int qua = 55;
        li.erase(find_if(li.begin(), li.end(), [qua](const Fruit& a){return a.quantity == qua;}));
        cout<< "list values(id 55 removed): " << endl;
        for(auto& i : li){
            cout << i.name << endl;
        }

        return 0;
    }   catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown exception" << endl;
        return 2;
    }
}
