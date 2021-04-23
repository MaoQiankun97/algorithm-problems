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


bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size()<=1) return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        int j;
        int start_t, end_t; vector<Interval> result;
        start_t = intervals[0].start;
        end_t = intervals[0].end;
        for (j = 1; j < intervals.size(); ++j) {
            if (end_t >= intervals[j].start) {
                end_t = max(end_t, intervals[j].end);
            } else {
                Interval t = Interval(start_t, end_t);
                result.push_back(t);
                start_t = intervals[j].start;
                end_t = intervals[j].end;
            }
        }

        Interval t = Interval(start_t, end_t);
        result.push_back(t);

        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<Interval> input = {Interval(1, 4), Interval(4, 5)};
    vector<Interval> r =  a.merge(input);
    for (int i = 0; i < r.size(); ++i) {
        cout<<"["<<r[i].start<<", "<<r[i].end<<"]"<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
