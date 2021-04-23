//
// Created by mqk on 2020/4/11.
//
#include "iostream"
using namespace std;
int main() {
    double w1, t1, l1;
    double w2, t2, l2;
    double w3, t3, l3;
    while (cin>>w1>>t1>>l1
            >>w2>>t2>>l2
            >>w3>>t3>>l3) {
        double max_1 = max(w1, max(t1, l1));
        double max_2 = max(w2, max(t2, l2));
        double max_3 = max(w3, max(t3, l3));
        if (max_1 == w1) {
            cout<<"W ";
        } else if (max_1 == t1) {
            cout<<"T ";
        } else {
            cout<<"L ";
        }
        if (max_2 == w2) {
            cout<<"W ";
        } else if (max_2 == t2) {
            cout<<"T ";
        } else {
            cout<<"L ";
        }
        if (max_3 == w3) {
            cout<<"W ";
        } else if (max_3 == t3) {
            cout<<"T ";
        } else {
            cout<<"L ";
        }
        printf("%.2f\n", (max_1 * max_2 * max_3 * 0.65 - 1) * 2);
    }

    return 0;
}
