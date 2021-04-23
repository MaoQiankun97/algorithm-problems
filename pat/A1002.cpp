//
// Created by mqk on 2020/3/14.
//

#include <iostream>
using namespace std;

int main() {
    int n1, n2, exponent;
    double coefficient;
    while (cin>>n1) {
        double coefficients[1001] = {0};
        int num = 0;
        for (int i = 0; i < n1; ++i) {
            cin>>exponent>>coefficient;
            if (coefficients[exponent] == 0) num++;
            coefficients[exponent] += coefficient;
            if (coefficients[exponent] == 0) num--;
        }
        cin>>n2;
        for (int i = 0; i < n2; ++i) {
            cin>>exponent>>coefficient;
            if (coefficients[exponent] == 0) num++;
            coefficients[exponent] += coefficient;
            if (coefficients[exponent] == 0) num--;
        }
        if (num == 0) {
            cout<<num<<endl;
        }
        cout<<num<<" ";
        for (int j = 100; j >= 0; --j) {
            if (coefficients[j] != 0) {
                num--;
                cout<<j<<" "<<coefficients[j];
                num > 0 ? cout<<" " : cout<<endl;
            }
        }
    }

    return 0;
}