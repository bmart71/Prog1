#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

template<typename C>
void print(const C& c, char sep = '\n'){
    cout << "Container elements:\n";

    for(const auto elem : c)
        cout << elem << sep;

    cout << endl;
}

template<typename C>
double sum(C& c){
    double sum;
    for(int i = 0; i < c.size(); i++){
        sum += c[i];
    }
    return sum;
}
/*
struct Less_than{
    double v;
    public:
        Less_than(double vv) : v{vv}{}
        bool operator()(const double val) { return val < v ;}
};
*/
int main() {
    try {
//1.:
        const string iname {"input_floats.txt"};
        ifstream ifs {iname};

        if (!ifs) throw runtime_error("Could not read file: "+ iname);

        vector<double> vd;
        for(double d ; ifs >> d;)
            vd.push_back(d);
//2.:        
        print(vd);
//3.:
        vector<int> vi(vd.size());

/*      for(auto& d : vd)
            vi.push_back(d);
*/

        copy(vd.begin(), vd.end(), vi.begin());
        print(vi);
//4.:
        for (int i = 0; i < vd.size(); i++){
            cout << vd[i] << '\t' << vi[i] << '\n';
        }
//5.:
        double vd_sum = sum(vd);
        int vi_sum = sum(vi);

        cout << vd_sum << endl;
        cout << vi_sum << endl;
//6.:
        cout << vd_sum - vi_sum << endl;
/*
        double i_sum = accumulate(vi.begin(), vi.end(), 0.0);
        double d_sum = accumulate(vd.begin(), vd.end(), 0.0);
        double diff_sum = inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, plus<double>(), minus<double>());
*/
//7.:
        reverse(vd.begin(), vd.end());
        print(vd);
//8.:
        double vd_mean = vd_sum / vd.size();
        cout << "Mean value of vd: " << vd_mean << endl;
//9.:
        vector<double> vd2;

        for(int i = 0; i < vd.size(); i++){
            if(vd[i] < vd_mean)
                vd2.push_back(vd[i]);
        }
/*
        auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
        vd2.resize(std::distance(vd2.begin(),it));
*/
        print(vd2);
//10.:
        std::sort(vd.begin(), vd.end());
        print(vd);

        return 0;
    }   catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown exception" << endl;
        return 2;
    }
}