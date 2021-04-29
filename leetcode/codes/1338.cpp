#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv{};
    gettimeofday(&tv,nullptr);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct HelpNode {
    int content;
    int frequency;
};

class Solution {
public:
    static int minSetSize(vector<int>& arr) {
        int total = arr.size();
        if (total <= 2) {
            return 1;
        }
        unordered_map<int, HelpNode> map;
        for (int i = 0; i < total; ++i) {
            if (map.find(arr[i]) != map.end()) {
                map[arr[i]].frequency++;
            } else {
                HelpNode item{};
                item.content = arr[i];
                item.frequency = 1;
                map[arr[i]] = item;
            }
        }
        vector<HelpNode> helpArr;
        auto begin = map.begin();
        while (begin != map.end()) {
            helpArr.push_back(begin->second);
            begin++;
        }
        sort(helpArr.begin(), helpArr.end(), compare);
        int result = 0;
        int count = 0;
        for (int i = 0; i < helpArr.size(); ++i) {
            result++;
            count += helpArr[i].frequency;
            if (count >= total / 2) {
                break;
            }
        }

        return result;
    }

private:
    static bool compare(HelpNode &a, HelpNode &b) {
//        int size = a.size();
        return  a.frequency > b.frequency;
    }
};

int main()
{
    int64_t t = getCurrentTime();
    vector<int> input = {3,3,3,3,5,5,5,2,2,7};
    cout<<Solution::minSetSize(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
