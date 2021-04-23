#include "iostream"
#include "vector"
#include <cmath>
#include "unordered_map"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        for(int i = 1;i<INT_MAX;i++){
            if(find(n,i)) return i;
        }

        return 0;
    }

    bool find(int n, int num){
        if(num==1){
            for(int i = 1;i<INT_MAX;i++){
                if(i*i>n)return false;
                if(i*i==n)return true;
            }
        }
        else{
            for(int i = 1; i*i<n;i++){

                if(find(n -i*i, num-1)) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution a;

    cout<<a.numSquares(136134123)<<endl;

    return 0;
}