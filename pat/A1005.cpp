//
// Created by mqk on 2020/3/27.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> getDigit(int N) {
    vector<int> result;
    while (N != 0) {
        result.push_back(N % 10);
        N /= 10;
    }

    return result;
}

string digitEnglish[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string N;
    while (cin>>N) {
        int sum = 0;
        for (int i = 0; i < N.length(); ++i) {
            sum += N[i] - '0';
        }
        if (sum == 0) {
            cout<<digitEnglish[0]<<endl;
            continue;
        }

        vector<int> _digits = getDigit(sum);
        for (int i = _digits.size() - 1; i >= 0; --i) {
            cout<<digitEnglish[_digits[i]];
            if (i > 0) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

//12345
//e: one five
//explain(15)