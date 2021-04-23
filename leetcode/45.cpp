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

class Solution {
public:
    int jump(vector<int> A) {
        int n = A.size();
        if(n<2)return 0;
        int level=0,currentMax=0,i=0,nextMax=0;

        while(currentMax-i+1>0){		//nodes count of current level>0
            level++;
            for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
                nextMax=max(nextMax,A[i]+i);
                if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level
            }
            currentMax=nextMax;
        }
        return 0;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> input = {1,2,3,4,5,6,7};
    cout<<a.jump(input);
    cout<<endl;
    cout<<getCurrentTime()-t;
    return 0;
}
