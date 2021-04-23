#include "iostream"
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return !(N & 1);
    }
};

int main() {
    Solution a;

    cout<<a.divisorGame(3);

    return 0;
}


