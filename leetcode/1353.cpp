#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "set"
#include <sys/time.h>      //添加头文件

using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv, nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

class Solution {
public:
#define N 100010
#define MP make_pair
    static multiset<pair<int,int> >S;
    static vector<int>in[N],out[N];
    static int maxEvents(vector<vector<int>>& events) {
        int mx=0,cnt=0;
        for (auto x:events){
            int l=x[0],r=x[1];
            mx=max(mx,r);
            in[l].push_back(cnt);
            out[r+1].push_back(cnt);
            cnt++;
        }
        int ans=0;
        for (int i=1;i<=mx;++i){
            for (auto x:in[i]) S.insert(MP(events[x][1],x));
            for (auto x:out[i]){
                auto it=S.find(MP(events[x][1],x));
                if (it!=S.end()) S.erase(it);
            }
            if (!S.empty()){
                S.erase(S.begin());
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int64_t t = getCurrentTime();
    vector<vector<int>> input = {
            {4, 3},
            {1, 4},
            {4, 6},
            {1, 7}
    };
    cout << Solution::maxEvents(input);
    cout << endl;
    cout << getCurrentTime() - t << endl;
    return 0;
}
