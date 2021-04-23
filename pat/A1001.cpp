#include <iostream>

using namespace std;

int main() {
    long long a1, a2;
    long long a3;
    while (cin>>a1>>a2) {
        a3 = a1 + a2;
        if (a3 == 0) {
            cout<<0<<endl;
            continue;
        }
        bool flag = a3 < 0;
        long long t[5]; int i = 0;
        a3 = a3 < 0 ? -a3 : a3;
        while (a3 >= 1000 || a3 % 1000 > 0) {
            t[i++] = a3 % 1000;
            a3 /= 1000;
        }
        if (flag) cout<<"-";
        for (int j = i-1; j >= 0; --j) {
            if (j == i-1) {
                cout<<t[j];
            } else {
                printf("%03lld", t[j]);
            }
            if (j > 0) {
                cout<<",";
            }
        }
        cout<<endl;
    }

    return 0;
}