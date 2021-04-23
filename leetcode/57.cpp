#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // 1 3   6 9 + 2 5
        // 1 5   6 9
        if (intervals.size()<=0)
            return { newInterval };
        vector<Interval> result;
        int s_t = -1; int e_t = intervals.size(); // s_t为第一个end比newIxx.start 大或等的元素的下标
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) continue;
            s_t = i;
            break;
        }
        if (s_t == -1) {
            intervals.push_back(newInterval);
            return intervals;
        }


        // 在s_t之前的元素end都小于插入元素的start, 故直接插入即可
        for (int j = 0; j < s_t; ++j) {
            result.push_back(intervals[j]);
        }

        // 再查找第一个start比插入元素end大的元素下标, 在那之前的元素都与插入元素有重合
        for (int k = s_t; k < intervals.size(); ++k) {
            if (intervals[k].start <= newInterval.end) continue;
            e_t = k;
            break;
        }
        int start; int end;
        start = min(intervals[s_t].start, newInterval.start);
        if (e_t-1>=0)
            end = max(intervals[e_t-1].end, newInterval.end);
        else
            end = newInterval.end;

        result.push_back(Interval(start, end));

        // 再插入剩余项
        for (int l = e_t; l < intervals.size(); ++l) {
            result.push_back(intervals[l]);
        }


        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<Interval> input = {Interval(1, 3), Interval(6, 9)};
    vector<Interval> r =  a.insert(input, Interval(2, 5));
    for (int i = 0; i < r.size(); ++i) {
        cout<<"["<<r[i].start<<", "<<r[i].end<<"]"<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
