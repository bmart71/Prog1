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
